#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],seat[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m,j=1,i=1,l=0,flag=0;
	for(int i=1;i<=k;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+k+1);
	while(i<=m){
		if(flag==0&&j!=n){
			seat[i][j]=a[k-l];
			if(seat[i][j]==r){
				cout<<i<<" "<<j;
				return 0;
			}
			l++;
			j++;
		}
		else if(flag==0&&j==n){
			flag=1;
			seat[i][j]=a[k-l];
			if(seat[i][j]==r){
				cout<<i<<" "<<j;
				return 0;
			}
			l++;
			i++;
		}
		else if(flag&&j!=1){
			seat[i][j]=a[k-l];
			if(seat[i][j]==r){
				cout<<i<<" "<<j;
				return 0;
			}
			l++;
			j--;
		}
		else if(flag&&j==1){
			flag=0;
			seat[i][j]=a[k-l];
			if(seat[i][j]==r){
				cout<<i<<" "<<j;
				return 0;
			}
			i++;
			l++;
		}
	}
	return 0;
}
