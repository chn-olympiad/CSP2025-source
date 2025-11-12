#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100010],b[100010],c[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2)
		{
			int sum = 0;
			if(a[1]>=b[1]&&a[1]>=c[1]&&a[1]>=a[2]){
			sum+=a[1];
			break;
			}  
			else if(b[1]>=a[1]&&b[1]>c[1]&&b[1]>b[2]){
			sum+=b[1];
			break;
			}  
			else if(c[1]>a[1]&&c[1]>b[1]&&c[1]>c[2]){
			sum+=c[1];
			break;
			}  
			else if(b[2]>a[2]&&b[2]>c[2]&&b[2]>b[1]){
			sum+=b[2];
			break;
			}  
			else if(c[2]>a[2]&&c[2]>b[2]&&c[2]>c[1]){
			sum+=c[2];
			break;
			}  
			else if(a[2]>b[2]&&a[2]>c[2]&&a[2]>a[1]){
			sum+=a[2];
			break;
			}  
			cout<<sum;
			return 0;
		}
	}
}
