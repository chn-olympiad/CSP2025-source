#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[10000];
bool cmp(int x,int y) {return x>y;}
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0),cin.tie(0);
	
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++)
	{
		cin>>a[i];
	}
	int mark=a[1];
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++)
	{
		if(a[i]==mark)
		{
			int o;
			if(i%m==0) o=i/m;
			else o=floor(i/m)+1;
			//cout<<o<<"    ";
			if(o%2==0)
			{
				cout<<o<<" "<<n-((i-1)%n);
				//cout<<" "<<i%m;
			}
			if(o%2==1)
			{
				cout<<o<<" "<<i-((o-1)*n);
			}
		}
	}
	
	
	
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

2 2 
100 99 98 97

2 2
97 100 98 99

3 3
94 95 96 97 98 99 100 93 92
*/
