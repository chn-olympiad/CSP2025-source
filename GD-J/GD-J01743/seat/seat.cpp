#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
		if(i==1){
			sum=a[i];
		}
	}
	int t=0;
	sort(a+1,a+1+l,greater<int>());
	for(int i=1;i<=l;i++){
		if(a[i]==sum){
			t=i;
			break;
		}
	}
	int ans=t/m;
	if(t%m!=0){
		ans++;
	}
	int ans2=t%n;
	if(ans%2==0){
		cout<<ans<<" "<<n-ans2+1;
	}else{
		cout<<ans<<" "<<ans2;
	}
	return 0;
}
