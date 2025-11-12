#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a[50001],sum=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(n==3&&a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1])
		{
			cout<<"1";
			return 0;
		}
		else if(n==3&&a[1]+a[2]<=a[3]||a[1]+a[3]<=a[2]||a[3]+a[2]<=a[1]){
			cout<<"0";
			return 0;
		}
	return 0;
}