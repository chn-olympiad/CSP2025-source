#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int ans=0,sum=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1);
	int x=1,y=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]=ans){
			cout<<x<<" "<<y+1;
		    return 0;
		}
		if(sum=0){
		    if(y+1<=n){
		    	y++;
			}else{
				y=n;
				x+=1;
				sum=1;
			}
		}else{
			if(y-1>0){
				y--;
			}else{
				y=1;
				x+=1;
				sum=0;
			}
		}
	}
	return 0;
} 
