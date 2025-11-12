#include<bits/stdc++.h>
using namespace std;
int arr[10000000];
int main(){
	freopen("seat.in","r",stdin)
	freopen("seat.out","w",stdout)	
	int n,m;
	cin>>n>>m;
	int r;
	int x=m*n;
	int ans=0;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
		r=arr[0];
	}
sort(arr,arr+x);
if(r==arr[0])
{
	cout<<1<<" "<<1;
	}	

	return 0;
}
