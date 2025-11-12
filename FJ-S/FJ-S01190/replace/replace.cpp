#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
inline int read();
const int N = 2e5 + 10,M= 5e6 + 10;
int dist[N];
char s1[M],s2[M];
int zuo[N];
int you[N];
vector<int> z[N],y[N],sz[N];
string ss1[N],ss2[N];
map<int,int> mp;
int len[N];
struct node{
	int zuo,you,sz;
};
vector<node> Sz[N];
bool cmp(node x,node y){
	return x.sz < y.sz;
}
int n,m;
void solve(){
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	int now1 = strlen(s1 + 1);
	int l = 0,r = 0;
	s1[0]='=';
	s2[0]='=';
	s1[now1+1]='=';
	s2[now1+1]='=';
	for(int i=1;i<=now1+1;i++){
		if(s1[i-1] == s2[i-1] && s1[i] != s2[i] && l == 0){
			l = i;
		}
		if(s1[i-1] != s2[i-1] && s2[i] == s1[i]){
			r = i;
		}
	}
	
	r--;
	//cout<<l<<" "<<r<<endl;
	int ans = 0;
	for(int i=1;i<=n;i++){
		
		if(len[i] >= r - l + 1){
			int can = 1;
			int le = 0;
			//cout<<ss1[1].length()<<" ";
			for(int j=1;j<=ss1[i].length();j++){
				//cout<<ss1[i][j]<<" ";
				if(ss1[i][j] == ss2[i][j]){
					le++;
					continue;
				}
				else break;
			}
			int ri = 0;
			for(int j=ss1[i].length();j>=1;j--){
				if(ss1[i][j] == ss2[i][j]){
					ri++;
					//cout<<ss1[i][j]<<" "<<ss2[i][j]<<endl;
					continue;
				}
				else break;
			}
			if(le >= l){
				can = 0;
			}
			if(ri + r >now1){
				can=0;
			}
			//cout<<can<<" "<<i<<endl;
			for(int j=l - le;j<=r + ri;j++){	
			//	cout<<ss1[i][j-(l - le)+1]<<" "<<s1[j]<<endl;
				//cout<<ss2[i][j-(l - le)+1]<<" "<<s2[j]<<endl;
				if((char)ss1[i][j-(l - le)+1] != (char)s1[j] || (char)ss2[i][j-(l - le)+1] != (char)s2[j]){
					//cout<<j<<"*";
					can=0;
				}
			
			}
			if(can) ans++;
		}
	}
	cout<<ans<<endl;
	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n=read();m=read();
	vector<int> vv;
	int mn=1e9;
	
	for(int i=1;i<=n;i++){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		ss1[i] = s1+1;
		ss2[i] = s2+1;
	
		//cout<<ss1[i]<<" "<<ss2[i]<<" "<<ss1[i].length()<<endl;
		int now = strlen(s1 + 1);
		for(int j=1;j<=now;j++){
			ss1[i][j] = s1[j];
			ss2[i][j] = s2[j];
		}
		len[i] = now;
		int d1=0,d2=0;
		for(int j=1;j<=now;j++){
			if(s1[j] == 'b') d1 = j;
			if(s2[j] == 'b') d2 = j;
		}
		zuo[i] = d1;
		you[i] = now - d1;
		//cout<<d1-d2<<" ";
		mn=min(mn,d1-d2);
		vv.push_back(d1-d2);
		
		
	}
	int ad = -mn + 1;
	for(int i=0;i<n;i++){
		z[vv[i] + ad].push_back(zuo[i+1]);
		y[vv[i] + ad].push_back(you[i+1]);
		sz[vv[i] + ad].push_back(len[i+1]);
		Sz[vv[i]+ad].push_back({zuo[i+1],you[i+1],len[i+1]});
	}//cout<<"_________________________________"<<endl;
	//cout<<1;
	for(int i=0;i<n;i++){
		if(!mp[vv[i] + ad]){
			mp[vv[i] + ad] =1;
			sort(Sz[vv[i]+ad].begin(),Sz[vv[i]+ad].end(),cmp);
			for(int j=0;j<Sz[vv[i]+ad].size();j++){
				z[vv[i]+ad][j] = Sz[vv[i]+ad][j].zuo;
				y[vv[i]+ad][j] = Sz[vv[i]+ad][j].you;
				sz[vv[i]+ad][j] = Sz[vv[i]+ad][j].sz;
			}
		}
		
	}
	if(m ==1){
		solve();
		return 0;
	}
	while(m--){
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int now1=strlen(s1+1);
		int now2=strlen(s2 + 1);
		if(now1 != now2){
			puts("0");
		}
		else{
			int d1=0,d2=0;
			for(int i=1;i<=now1;i++){
				if(s1[i] =='b') d1=i;
				if(s2[i]== 'b') d2=i;
			}
			int nn = d1 - d2 + ad;
			int le = d1;
			int re = now1 - d1;
			if(!z[nn].size()){
				puts("0");
			}
			else{
				int szz = z[nn].size();
				//int t1=upper_bound(z[nn].begin(),z[nn].end(),le) - (z[nn].begin());
				//int t2=upper_bound(y[nn].begin(),y[nn].end(),re)-(y[nn].begin());
				int bg =upper_bound(sz[nn].begin(),sz[nn].end(),now1) -(sz[nn].begin());
				vector<int> zz,yy;
				for(int i=0;i<bg;i++){
					zz.push_back(z[nn][i]);
					yy.push_back(y[nn][i]);
				}
				sort(z[nn].begin(),z[nn].begin()+bg);
				sort(y[nn].begin(),y[nn].begin()+bg);
				int t1=upper_bound(z[nn].begin(),z[nn].begin()+bg,le)-(z[nn].begin());
				int t2=upper_bound(y[nn].begin(),y[nn].begin()+bg,re)-(y[nn].begin());
				//cout<<t1+t2-bg<<endl;
				printf("%d\n",t1+t2-bg);
				for(int i=0;i<bg;i++){
					z[nn][i] = zz[i];
					y[nn][i] = yy[i];
				}
		}
		}
	}
	return 0;
}
inline int read(){
	char x=getchar();
	int res = 0;
	int f = 1;
	while(x < '0' || x >'9'){
		if(x == '-') f =-1;
		x = getchar();
	}
	while(x >='0' && x <='9'){
		res = res * 10 + (x -'0');
		x=getchar();
	}
	return res * f;
}

