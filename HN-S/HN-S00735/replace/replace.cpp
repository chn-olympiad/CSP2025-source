#include<bits/stdc++.h>
using namespace std;
#define mxn 5000010
#define ull unsigned long long
struct node{int nxt[27],fail,val,dep;vector<int>h;};
node act[mxn];
ull v[27],m10[mxn];
int n,q,c;
char s[mxn],qs1[mxn],qs2[mxn];
ull hs1[mxn],hs2[mxn];
ull th1[mxn],th2[mxn];
int len[mxn];
void insert(char* S,int Len,int Id){
	int now=0;
	for(int i=1;i<=Len;i++){
		int id=S[i]-'a'+1;
		if(!act[now].nxt[id])
			act[now].nxt[id]=++c,act[c].dep=act[now].dep+1;
		now=act[now].nxt[id];
	}
	act[now].h.push_back(Id);
}
void getfail(){
	queue<int> q;
	for(int i=1;i<=26;i++)
		if(act[0].nxt[i])q.push(act[0].nxt[i]);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=1;i<=26;i++){
			if(act[u].nxt[i]){
				act[act[u].nxt[i]].fail=act[act[u].fail].nxt[i];
				q.push(act[u].nxt[i]);
			}
			else act[u].nxt[i]=act[act[u].fail].nxt[i];
		}
	}
}
void solve(){
	int ans=0;
	cin>>qs1+1>>qs2+1;
	int len1=strlen(qs1+1);
	int mnp=0,mxp=0;
	for(int i=1;i<=len1;i++){
		th1[i]=th1[i-1]+m10[i-1]*v[qs1[i]-'a'+1];
		th2[i]=th2[i-1]+m10[i-1]*v[qs2[i]-'a'+1]; 
		if(qs1[i]!=qs2[i]){
			if(!mnp)mnp=i;
			mxp=i;
		}
	}
	int now=0;
	for(int i=1;i<=len1;i++){
		int id=qs1[i]-'a'+1;
		if(!act[now].nxt[id]){
			while(now&&!act[now].nxt[id])
				now=act[now].fail;
		}
//		cout<<now<<'\n';
		if(!now||i<mxp)continue;
		for(int j=0;j<act[now].h.size();j++){
			int Id=act[now].h[j];
			if(mxp-len[Id]+1>mnp)continue;
			if(hs1[Id]*m10[mxp-len[Id]]==th2[i]-th2[i-len[Id]])ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(0));
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=26;i++)v[i]=rand();
	m10[0]=1;
	for(int i=1;i<=mxn-10;i++)m10[i]=m10[i-1]*26;
	for(int i=1;i<=n;i++){
		cin>>s+1,len[i]=strlen(s+1);
		for(int j=1;j<=len[i];j++){
			hs1[i]+=m10[j-1]*v[s[j]-'a'+1];
		}
		insert(s,len[i],i);
		cin>>s+1;
		for(int j=1;j<=len[i];j++){
			hs2[i]+=m10[j-1]*v[s[j]-'a'+1];
		}
	}
	getfail();
	while(q--)solve();
	return 0;
}
// ¼Ä 
