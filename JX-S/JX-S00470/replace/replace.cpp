#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
const int SZ=2e5+3;
const int SZ2=5e6+3;
const int BASE=131;

int n,q,l[SZ2],r[SZ2];
struct node{
	int len;
	ull h1,h2;
}s[SZ];
string str,t1,t2;
ull H1[SZ2],H2[SZ2],P[SZ2];

ll read(){
	ll res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=(res<<3)+(res<<1)+(c-'0');
		c=getchar();
	}
	return res*f;
}
bool cmp(node x,node y){return x.len<y.len;}
ull get_hash(string str,int len){
	ull res=0;
	for(int i=0;i<len;i++){
		res=res*BASE+str[i];
	}
	return res;
}
ull Hash1(int L,int R){return H1[R]-H1[L-1]*P[R-L+1];}
ull Hash2(int L,int R){return H2[R]-H2[L-1]*P[R-L+1];}
void init(){
	P[0]=1;
	t1=(string)"a"+t1;
	t2=(string)"a"+t2;
	int len=t1.size();
	for(int i=1;i<len;i++){
		P[i]=P[i-1]*BASE;
		H1[i]=H1[i-1]*BASE+t1[i];
		H2[i]=H2[i-1]*BASE+t2[i];
	}
	for(int i=0;i<=len;i++) l[i]=r[i]=0;
	r[len]=len;
	for(int i=1;i<len;i++){
		if(l[i-1]==i-1&&t1[i]==t2[i]) l[i]=i;
		else l[i]=l[i-1]; 
		//printf("l[%d]=%d\n",i,l[i]);
	}
	for(int i=len-1;i>=1;i--){
		if(r[i+1]==i+1&&t1[i]==t2[i]) r[i]=i;
		else r[i]=r[i+1];
		//printf("r[%d]=%d\n",i,r[i]);
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str;
		s[i].len=str.size();
		s[i].h1=get_hash(str,s[i].len);
		cin>>str;
		s[i].h2=get_hash(str,s[i].len);
	}
	sort(s+1,s+1+n,cmp);
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			puts("0");
			continue;
		}
		init();
		int len=t1.size();
		//printf("len=%d\n",len);
		for(int i=1;i<=n;i++){
			//printf("s[%d].len=%d\n",i,s[i].len);
			for(int j=1;j+s[i].len-1<len;){
				int k=j+s[i].len-1;
				//cout<<Hash1(j,k)<<" "<<s[i].h1<<"\n";
				//cout<<Hash2(j,k)<<" "<<s[i].h2<<"\n";
				//printf("%d %d %d %d\n",l[j-1],j-1,r[k+1],k+1);
				if(l[j-1]==j-1&&r[k+1]==k+1&&Hash1(j,k)==s[i].h1&&Hash2(j,k)==s[i].h2){
					//printf("%d %d %d %d\n",l[j-1],j-1,r[k+1],k+1);
					ans++;
				}
				if(l[j-1]!=j-1) break;
				else if(r[k+1]!=k+1) j+=r[k+1]-(k+1);
				else j++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


