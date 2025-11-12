#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=1;
	cin>>n>>m;
	int tal=n*m;
	for(int i=1;i<=tal;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+tal+1);
	for(int i=1;i<=tal;i++){
		//cout<<a[i]<<endl;
		if(a[i]==ans){
			ans=i;
			break;
		}
	}
	for(int i=1;i<=tal-ans;i++){
		//cout<<x<<" "<<y<<endl;
		if(((i-1)/n+1)%2==1){
			if(i%n==0){
				x++;
			}
			else y++;
		}else{
			if(i%n==1){
				x++;
			}
			else y--;
		}
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}