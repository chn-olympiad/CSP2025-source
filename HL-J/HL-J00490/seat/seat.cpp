#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n*m+1;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<n*m+1;i++){
		if(sum==a[i]){
			//cout<<i<<endl;
			int c=i%n;
			int b=i-c;
			//cout<<c<<" "<<b;
			if(sum==a[n*m]){
				cout<<1<<" "<<1;
				break;
			}
			if((b/n)%2==1){
				if(c==0){
					cout<<n<<" "<<m-(b/n)+1;
					break;
				}
				cout<<c<<" "<<m-(b/n);
				break;
			}
			if((b/n)%2==0){
				if(c==0){
					cout<<1<<" "<<m-(b/n)+1;
					break;
				}
				cout<<n-c+1<<" "<<m-(b/n);
				break;
			}
		}
	}
	return 0;
}
/*
3 3 95 99 98 97 96 94 93 92 91
5 5 1 19 24 25 23 20 18 22 21 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 
4 5 19 20 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
4 4 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
*/
