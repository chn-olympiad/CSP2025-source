#include<bits/stdc++.h>
using namespace std;
struct node
{
	int value1;
	int value2;
	int value3;
}a[10000];
bool cmp(node x,node y)
{
	if(x.value1!=y.value1) return x.value1>y.value1;
	else if(x.value2!=y.value2) return x.value2>y.value2;
	else return x.value3>y.value3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n,a1,a2,a3,cnt1,cnt2,cnt3,sum1=0,sum2=0,sum3=0;
	cin>>t;
	while(t--)
	{
		cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1>>a2>>a3;
			if(max(max(a1,a2),a3)==a1)
			{
				sum1+=a1;
				cnt1++;
			}
			else if(max(max(a1,a2),a3)==a2)
			{
				cnt2++;
				sum2+=a2;
			}
			else 
			{
				cnt3++;
				sum3+=a3;
			}
		}		
	}
	cout<<sum1<<endl<<sum2<<endl<<sum3;
	return 0;
}
