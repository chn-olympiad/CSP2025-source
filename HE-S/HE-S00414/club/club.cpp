#include <bits/stdc++.h>
using namespace std;
struct num{
	int q1,q2,q3;
}a[10000000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t){
		int n,x1=0,x2=0,x3=0;
		cin>>n;
		int m=n/2;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].q1>>a[i].q2>>a[i].q3;
			if(a[i].q1>a[i].q2>a[i].q3)
			{
				if(x1<m)
				{
				x1++;
				ans+=a[i].q1;
				}
				else if(x2<m)
				{	
				x2++;
				ans+=a[i].q2;
				}
				else
				{
				x3++;
				ans+=a[i].q3;
				}
			}
			else if(a[i].q1>a[i].q3>a[i].q2){
				if(x1<m)
				{
				x1++;
				ans+=a[i].q1;
				}
				else if(x3<m)
				{	
				x3++;
				ans+=a[i].q3;
				}
				else
				{
				x2++;
				ans+=a[i].q2;
				}
			}
			else if(a[i].q2>a[i].q1>a[i].q3){
				if(x2<m)
				{
				x2++;
				ans+=a[i].q2;
				}
				else if(x1<m)
				{	
				x1++;
				ans+=a[i].q1;
				}
				else
				{
				x3++;
				ans+=a[i].q3;
				}
			}
			else if(a[i].q2>a[i].q3>a[i].q1){
				if(x2<m)
				{
				x2++;
				ans+=a[i].q2;
				}
				else if(x3<m)
				{	
				x3++;
				ans+=a[i].q3;
				}
				else
				{
				x1++;
				ans+=a[i].q1;
				}
			}
			else if(a[i].q3>a[i].q1>a[i].q2){
				if(x3<m)
				{
				x3++;
				ans+=a[i].q3;
				}
				else if(x1<m)
				{	
				x1++;
				ans+=a[i].q1;
				}
				else
				{
				x2++;
				ans+=a[i].q2;
				}
			}
			else if(a[i].q3>a[i].q2>a[i].q1){
				if(x3<m)
				{
				x3++;
				ans+=a[i].q3;
				}
				else if(x2<m)
				{	
				x2++;
				ans+=a[i].q2;
				}
				else
				{
				x1++;
				ans+=a[i].q1;
				}
			}		
			
		}
	cout<<ans<<endl;
    t--;
	}
	return 0;
} 

