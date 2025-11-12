#include<bits/stdc++.h>

using namespace std;
void read(int &x){
	x=0;
	int fla=0;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')fla=1;
	x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';
	if(fla)x=-x;
	return;
}
const int N=2e5+5,M=5e6+5;
const long long mod=998244353,base=131;
int sl[N],sr[N],len[N],k1,k2;
char c1[M],c2[M];
string s1,s2;
void init(){
	// cin>>s1>>s2;
	// for(int i=1;i<=s1.size();i++)c1[i]=s1[i-1];k1=s1.size();
	// for(int i=1;i<=s2.size();i++)c2[i]=s2[i-1];k2=s2.size();
	k1=k2=0;
	//cout<<"ytjyjuyju"<<endl;
	char c;
	while(!isgraph(c=getchar()));
	c1[++k1]=c;
	while(isgraph(c=getchar()))c1[++k1]=c;
	while(!isgraph(c=getchar()));
	c2[++k2]=c;
	while(isgraph(c=getchar()))c2[++k2]=c;
	// //cout<<"#$#$df"<<endl;
}
long long h[N][3],hl[M],hr[M];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	read(n);read(q);
	//cin>>n>>q;
	for(int i=1;i<=n;i++){
		init();len[i]=k1;
		for(int j=1;j<=k1;j++){
			if(c1[j]!=c2[j]){
				if(!sl[i])sl[i]=j;
				sr[i]=j;
			}
		}
		if(!sl[i]){
			len[i]=-1;
			continue;
		}
		for(int j=sl[i]-1;j;j--){
			h[i][0]=(h[i][0]*base+c1[j])%mod;
		}
		for(int j=sr[i]+1;j<=k1;j++){
			h[i][2]=(h[i][2]*base+c1[j])%mod;
		}
		for(int j=sl[i];j<=sr[i];j++){
			h[i][1]=(h[i][1]*base+c1[j])%mod;
			h[i][1]=(h[i][1]*base+c2[j]+c1[j]*1145)%mod;
		}
	}
	for(int i=1;i<=q;i++){
		init();
		if(k1!=k2){
			puts("0");
			continue;
		}
		int l=0,r=0;
		for(int j=1;j<=k1;j++){
			if(c1[j]!=c2[j]){
				if(!l)l=j;
				r=j;
			}
		}
		long long has=0;
		for(int j=l;j<=r;j++){
			has=(has*base+c1[j])%mod;
			has=(has*base+c2[j]+c1[j]*1145)%mod;
		}
		for(int j=l-1;j;j--){
			//cout<<j<<endl;
			hl[l-j]=(hl[l-j-1]*base+c1[j])%mod;
		}
		//cout<<has<<endl;
		for(int j=r+1;j<=k1;j++){
			//cout<<j<<endl;
			hr[j-r]=(hr[j-r-1]*base+c1[j])%mod;
		}
		//cout<<"FGbhdfghf"<<endl;
		int ans=0;
		for(int j=1;j<=n;j++){
			if(len[j]==-1)continue;
			if(has!=h[j][1])continue;
			if(h[j][0]!=hl[sl[j]-1]||l<sl[j])continue;
			if(h[j][2]!=hr[len[j]-sr[j]]||k1-r<len[j]-sr[j])continue;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
//g++ c.cpp -o c -std=c++14 -static -Wall