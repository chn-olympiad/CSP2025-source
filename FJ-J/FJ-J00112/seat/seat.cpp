#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int a[1005];
	int n,m;
	cin>>n>>m;
	int q=n*m;
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	a[0]=a[1];
	sort(a+1,a+q+1);
	int x=1,y=0;
	for(int i=q;i>=1;i--){
		if(x%2==1){
			y++;
			if(y>n){
				x++;
				y-=1;
			}
		}
		else{
			y--;
			if(y<1){
				x++;
				y+=1;
			}
		}
		if(a[i]==a[0])break;
	}
	cout<<x<<' '<<y;
	return 0;
} 
