#include<bits/stdc++.h>
using namespace std;
int t,n;
struct number
{
	int ai_1;
	int ai_2;
	int ai_3;
} a[10010];

int main()
{
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	cin>>t;
	while(t)
	{
		int like=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int n1=0,n2=0,n3=0;
			cin>>a[i].ai_1>>a[i].ai_2>>a[i].ai_3;
			if(a[i].ai_1>a[i].ai_2&&a[i].ai_1>a[i].ai_3&&n1<=n/2)
			{
				like+=a[i].ai_1;
				n1++;
			}
			else if(a[i].ai_2>a[i].ai_3&&a[i].ai_2>a[i].ai_1&&n2<=n/2)
			{
				like+=a[i].ai_2;
				n2++;
			}
			else
			{
				like+=a[i].ai_3;
				n3++;
			}
		}
		cout<<like<<endl;
		t--;
	}
	return 0;
 } 
