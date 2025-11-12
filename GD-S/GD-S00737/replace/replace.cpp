#include<bits/stdc++.h>
using namespace std;
const long long N=1e9+7,p=29;
map <long long,int> ma;
int n,q;
long long pw[200005];
string s[200005][3],t[200005][3];
long long len[200005],dif[200005],len2[200005],dif2[200005];
vector<long long> v1[200005][3],v2[200005][3];
long long power(long long x,long long y){
	long long res=1,base=x;
	while(y){
		if(y&1)res=res*base%N;
		base=base*base%N;y>>=1;
	}
	return res%N;
}
long long f(int s,int t,vector<long long> v){
	if(s>t)return 0;
	return (v[t]-v[s-1]*pw[t-s+1])%N;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++)cin>>t[i][1]>>t[i][2]; 
	pw[0]=1;ma[1]=1;
	for(int i=1;i<=2e5;i++)pw[i]=pw[i-1]*p%N,ma[pw[i]]=i+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			long long now=0;
			v1[i][j].push_back(now);
			for(int k=0;k<len[i];k++){
				now=now*p+(long long)(s[i][j][k]-'a');
				now%=N;
				v1[i][j].push_back(now);
			}
		}
		len[i]=s[i][1].size();
		dif[i]=v1[i][1][len[i]]-v1[i][2][len[i]];
		dif[i]=(dif[i]%N+N)%N;
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=2;j++){
			long long now=0;
			v2[i][j].push_back(now);
			for(int k=0;k<t[i][j].size();k++){
				now%=N;
				now=now*p+(long long)(t[i][j][k]-'a');
				v2[i][j].push_back(now);
			}
		}
		len2[i]=t[i][1].size();
		dif2[i]=v2[i][1][len2[i]]-v2[i][2][len2[i]];
		dif2[i]=(dif2[i]%N+N)%N;
	}
	for(int i=1;i<=q;i++){
		int temp=0;
		for(int j=1;j<=n;j++){
			long long u=dif2[i]*power(dif[j],N-2)%N;
			u=(u%N+N)%N;
			int o=ma[u];
			if(o==0)continue;
			o--;
			if(o+len[j]>len2[i])continue;
			bool pan=true;
			if(f(1,o,v2[i][1])!=f(1,o,v2[i][2]))pan=false;
			if(f(o+1,o+len[j],v2[i][1])!=f(o+1,o+len[j],v1[j][1]))pan=false;
			if(f(o+1,o+len[j],v2[i][2])!=f(o+1,o+len[j],v1[j][2]))pan=false;
			if(f(o+len[j]+1,len2[i],v2[i][1])!=f(o+len[j]+1,len2[i],v2[i][2]))pan=false;
			if(pan)temp++;
		}
		cout<<temp<<"\n";
	}
	return 0;
}
