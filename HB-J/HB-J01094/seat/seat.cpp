#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;//n=2 m=2
	int a[n*m];//n*m=4
	for(int i=0;i<n*m;i++){
		cin>>a[i];//98 99 100 97
		}
		int x=a[0];//98
		sort(a,a+n*m);
		for(int i=n*m;i>=0;i--){
			if(a[i]==x){//i=6
				int y=(n*m-n)/n+1;//3
				cout<<y<<" ";
				if(y%2==0){
					cout<<n-(m*n-n)%n;//2
					break;
		}
					else {
						cout<<(n*m-n)%n;
						break;
						}
				}
			}
		
	}
