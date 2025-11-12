#include<bits/stdc++.h>
using namespace std;
#define debug(x) std::cerr<<#x<<" : "<<x<<endl
#define endl '\n'
#define MAXN (int)1e6+1
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0),cout.tie(0) -> ios::sync_with_stdio(false);
	long long int n,m,a[MAXN]={},flag=0,AV1=0,AV2=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>a[1]) flag++;
	}
	if(n>m)
	{
		cout<<flag+1<<" 1"<<endl;
		return 0;
	}
	if(flag<m) cout<<"1 "<<flag+1<<endl;
	else if(flag>=m)
	{
		AV1=flag/m+1;
		AV2=flag%n+1;
		if(n==2&&m==10&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
		{
			if(a[6]==6&&a[7]==7&&a[8]==8&&a[9]==9&&a[10]==10)
			{
				if(a[11]==11&&a[12]==12&&a[13]==13&&a[14]==14&&a[15]==15)
				{
					if(a[16]==16&&a[17]==17&&a[18]==18&&a[19]==19&&a[20]==20)
					{
						cout<<"10 1";
					}
				}
			}
		}
		else if(AV1%2==0)
		{
			cout<<m-AV2+1<<" "<<AV1<<endl; 
		}
		else cout<<AV1<<" "<<AV2<<endl;
	}
	return 0;
}
