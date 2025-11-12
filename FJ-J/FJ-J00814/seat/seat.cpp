#include<bits/stdc++.h>
using namespace std;
long long a[10000000],n,m,b[1000][1000];
int id=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	int k=a[1];
    sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
			id=n*m-i+2;
			break;
		}
	}
	int top=n*m+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			top--;
			if(i%2==1){
				b[i][j]=a[top];
				if(a[top]==k){
					cout<<i<<" "<<j;
					return 0;
				}
	        }else{
				b[i][m-j+1]=a[top];
				if(a[top]==k){
					cout<<i<<" "<<m-j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}

