#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int tmp,k=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)tmp=a[i];
		if(a[i]>tmp){
			k++;
		}
	}
	int x=1,y=0;
	for(int i=1;i<=n*m;i++){
		y++;
		if(y==n+1){
			x++;
			y=1;
		}
		if(i==k){
			if(x%2==1){
				cout<<x<<" "<<y<<endl;
			}else{
				cout<<x<<" "<<n-y+1<<endl;
			}
		}
	}
	return 0;
}
