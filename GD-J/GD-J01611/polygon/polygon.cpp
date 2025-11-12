#include<bits/stdc++.h>
using namespace std;
int n,a[5555],maxx,sum;
const int q=998244353;
long long summ;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	if(n<=2){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]),sum+=a[i];
	if(n==3){
		if(sum>2*maxx) cout<<"1";
		else cout<<"0";
		return 0; 
	}
	if(maxx==1){
		for(int i=3;i<=n;i++)
			for(int j=i;j>=1;j--)
				summ=(summ*a[i]/j)%q;
		cout<<summ;
		return 0;
	}
	cout<<"0";
	return 0;
}
