#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1],t=0;
	sort(a+1,a+1+m*n);
	for(int i=n*m;i>=1;i--){
        t++;
		if(a[i]==k){
		   break;
		}
	}
	int l=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			l++;
			if(l==t){
				cout<<x<<" "<<y;
			}else{
				if(x!=i){
					x=i;
					y=1;
				}
				if(j%2==1){
					y++;
				}else{
					y--;
				}
			}
		}
	}
	cout<<t;
	return 0;
} 
