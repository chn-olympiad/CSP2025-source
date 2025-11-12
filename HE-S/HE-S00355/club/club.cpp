#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	int s[t];
	cin >> t;
	for(int i = 0;i<t;i++)
	{
		int num=0;
		int n;
		cin >> n; 
		for(int j=0;j<n;j++)
		{	
		    int time1=0,time2=0,time3=0;
			int p[3];
			cin >> p[0] >> p[1] >> p[2];    
			int maxn=max(max(p[0],p[1]),p[2]);
			num += maxn;
		}  
		s[i] = num;
	}
	for(int i=0;i<t;i++)
	{
		cout << s[i] << endl;
	}
	
	return 0;
}
