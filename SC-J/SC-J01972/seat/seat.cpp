#include<bits/stdc++.h>
using namespace std;
#define len n*m
int n,m;
int arr[110],xr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=len;i++){cin>>arr[i];if(i==1)xr=arr[i];}
	sort(arr+1,arr+1+len);
	int wz=0;
	for(int i=len;i>=1;i--)if(arr[i]==xr){wz=len-i+1;break;}
	int x1=(wz%n==0)? wz/n:wz/n+1;
	int y1=(x1%2==1)? wz-(x1-1)*n:m-(wz-(x1-1)*n)+1;
	cout<<x1<<' '<<y1;
	return 0;
}
