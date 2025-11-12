#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int t1=1,t2=1,sum=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)	cin>>a[i];
    k=a[1];
	sort(a+1,a+n*m+1,cmp);	
	while(1)
	{
		if(a[sum]==k)
		{
			cout<<t2<<" "<<t1;
			break;
		}
		if(t1<n&&t2%2==1) 
		{
			t1++;
			sum++;
			continue;
		}
		if(t1<n&&t1>1&&t2%2==0||t1==n&&t2%2==0)
		{
			t1--;
			sum++;
			continue;
		}
		if(t1==n&&t2%2==1||t1==1&&t2%2==0)
		{
			t2++;
			sum++;
			continue;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
