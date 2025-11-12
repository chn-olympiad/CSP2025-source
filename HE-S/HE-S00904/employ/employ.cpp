#include <iostream>
#include <cstdio>
using namespace std;
const int N=505;
const long long P=998244353;
int n,m,s[N],c[N],is,cnt,pre[N],sum[N],pr[N];
long long ans=1,anss;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i+=1){
		cin>>s[i];
		if(s[i]==0)is=1;
		ans=(ans*i)%P;
		pre[i]=pre[i-1]+s[i];
	}
	for(int i=1;i<=n;i+=1){
		cin>>c[i];
		if(!c[i])cnt+=1;
		sum[c[i]]+=1;
	}
	if(n-cnt<m){
		cout<<0<<endl;
	}else if(!is){
		cout<<ans<<endl;
	}else{
		for(int i=1;i<=n;i++){
			pr[i]=pr[i-1]+sum[i];
		}
		for(int i=1;i<=n;i++){
			anss=(anss*pr[pre[i]])%P;
		}
		cout<<ans<<endl;
	}
	return 0;
}

