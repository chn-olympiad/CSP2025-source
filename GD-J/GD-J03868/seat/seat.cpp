#include<iostream>
#include<algorithm>
using namespace std;
int a[114514];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int A_score;cin>>A_score;
	a[1]=A_score;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int A_id;
	for(int i=n*m;i>=1;i--)
		if(a[i]==A_score)
		{		
			A_id=n*m-i+1;
			break;
		}
	//cout<<"id:"<<A_id<<" ";
	int x=1,y=1,dir=1;
	for(int i=1;i<A_id;i++)
	{
		if(y==1&&x%2==1) x++,dir=1;
		else if(y==n&&x%2==0) x++,dir=-1;
		else y+=dir;
		//cout<<x<<" "<<y<<endl;
	}
	cout<<x<<" "<<y<<endl;		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
