#include<bits/stdc++.h>
using namespace std;
int n,m,arr[105],x,y;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>arr[i];
	int d=arr[1];
	sort(arr+1,arr+n*m+1);
	int ans=0;
	for(int i=n*m;i>=1;i--){
		if(arr[i]==d){
			ans=n*m-i+1;
			break;
		}
	}
	x=ans/n;
	if(ans%n!=0)x++;
	y=ans-((x-1)*n);
	if(x%2==1){
		cout<<x<<' '<<y;
	}else{
		cout<<x<<' '<<n-y+1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
