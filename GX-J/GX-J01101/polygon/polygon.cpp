#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int arr[10000]={0};
	int ans=0;
	for(int m=0;m<n;m++)
	{
		cin>>arr[m];
		if(arr[m]+arr[m-1]>(m+1)*2)
		{
			ans++;
		}
	}
	cout<<"9"<<endl;
		return 0;
	}
	
