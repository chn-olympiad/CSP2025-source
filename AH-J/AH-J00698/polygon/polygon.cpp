#include<bits/stdc++.h>
using namespace std;
#define ul unsigned long int
ul n;
long long ans=0;
const long long mod=998244353;
int a[5010];
void f(string s,ul numstk,ul sumlen,ul maxlen){
	if(s.size()==n){
		if(numstk<3)return;
		if(maxlen*2>=sumlen)return;
		ans%=mod;
		ans+=1;
		ans%=mod;
		return;
	}
	f(s+'1',numstk+1,sumlen+a[s.size()+1],a[s.size()+1]);
	f(s+'0',numstk,sumlen,maxlen);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int maxai=-1;
	cin>>n;
	for(ul i=1;i<=n;i++){
		cin>>a[i];
		maxai=max(a[i],maxai);
	}
	sort(a+1,a+n+1);
	if(maxai!=1){
		f("",0,0,0);
		cout<<ans%mod<<endl;
	}else{
		long long ansk=0;
		for(ul i=3;i<=n;i++){
			long long c1=1,c2=1;
			for(ul j=n;j>=n-i+1;j--){
				c1*=j;
				c1%=mod;
			}
			for(ul j=1;j<=i;j++){
				c2*=j;
				c2%=mod;
			}
			ansk+=(c1/c2)%mod;
			ansk%=mod;
		}
		cout<<ansk%mod<<endl;
	}
	return 0;
}
