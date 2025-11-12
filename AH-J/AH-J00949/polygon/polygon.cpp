#include<bits/stdc++.h>
using namespace std;
int n,a[5005],st=1,en=2,te=3,l;
bool pd[5005];
void f(int k){
	if(te>n){
		memset(pd,0,sizeof(pd));
		st++;
		if(st>=n-k)st=1,k++;
		en=st+k;
		te=en+1;
	}int ans=0;
	for(int i=st;i<=en;i++){
		if(pd[i]==0){
			ans+=a[i];
			cout<<a[i]<<' ';
		}
	}cout<<a[te]<<endl<<ans<<endl;
	if(ans>a[te]){
		l++,te++;
		cout<<-1<<endl;
	}
	else{
		pd[en]=1;
		en++;
		te=en+1;
	}if(k<=n-2)f(k);
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	f(1);
	cout<<l-1;
}
