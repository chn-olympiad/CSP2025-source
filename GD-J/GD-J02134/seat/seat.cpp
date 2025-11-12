#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s[101][101]={};
	int a[10086]={};
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==cnt){
			cnt=n*m-i+1;
			break;
		}
	}
	int sum=1;
	int x=1,y=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(sum==cnt){
				cout<<y<<" "<<x;
				return 0;
			}	
			if(y%2==1){
				if(x==n){
					y++;
				}else{
					x++;
				}
			}else{
				if(x==1){
					y++;
				}else{
					x--;
				}
			}
			sum++;
		}
	}
	return 0;
} 

