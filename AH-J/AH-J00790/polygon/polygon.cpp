#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long a[100005],n,fac[25]={1,1};
long long ans=0;
bool cmp(int x,int y){
	return x>y;
}
void fi(int want,int start,int now){
	if(now>=want){
		if(now==want&&start>n)return;
		if(now!=want)ans++;
		for(int i=1;i<=n-start+1;i++){
			long long k=fac[n-start+1]/(fac[i]*fac[n-start+1-i]);
			//out<<want<<" "<<now<<" "<<k<<endl;
			ans+=k;
			ans%=MOD;
		}
		//cout<<want<<" "<<now<<" "<<ans<<endl;
		return ;
	}
	for(int i=start;i<=n;i++){
		fi(want,i+1,now+a[i]);
	}
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    for(int i=2;i<=21;i++)
		fac[i]=fac[i-1]*i;
    cin>>n;
    for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		fi(a[i],i+1,0);
	}
	cout<<ans<<endl;
    return 0;
}
