#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=7;i<=(1<<n)-1;i++){
		int sum=0,mx=0,t=0,flag=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<j-1)){
				t++;
				sum+=a[j];
				mx=max(mx,a[j]);
			}
		}
		if(sum>2*mx&&t>=3)ans++;
	}
	cout<<ans;
	return 0;
}
