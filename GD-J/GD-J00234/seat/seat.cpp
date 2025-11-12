#include<bits/stdc++.h> 
using namespace std;
long long a[10005];
int n,m;
int x,y;
int sum;
int qq;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	qq=a[1];
	sort(a+1,a+n*m+1);
	sum=n*m;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				if(a[sum]==qq){
					cout<<i<<" "<<j;
					return 0;
				}
				sum--;
			}
		}
		else{
			for(int j=1;j<=m;j++){
				if(a[sum]==qq){
					cout<<i<<" "<<j;
					return 0;
				}
				sum--;
			}
		}
	}
	return 0;
}
