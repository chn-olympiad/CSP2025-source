#include<bits/stdc++.h>
using namespace std;
int a[1001]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	int num=a[1];
	sort(a+1,a+n*m+1);
	int ans=0;
	int j=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==num){
			ans=j;
			break;
		}
		j++;
	}
	cout<<(ans+m-1)/m<<" ";
	if(((ans+m-1)/m)%2==1){
		if(ans%m==0){
			cout<<m;
		}
		else{
			cout<<ans%m;
		}
	}
	else{
		if(ans%m==0){
			cout<<1;
		}
		else{
			cout<<m-(ans%m);
		}
	}
	return 0;
}
