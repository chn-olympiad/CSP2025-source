//GZ-S00743 华东师范大学附属贵阳学校 陈泓睿
#include<bits/stdc++.h> 
using namespace std;
struct a
{
	int a1;
	int a2;
	int a3;
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,cnt,sum;
	cin >> t >> n;
	a b[10000000] ={};
	for(int i = 0; i <= n; i++)
	{
		cin >> b[i].a1 >> b[i+1].a2 >> b[i+2].a3;
	}
	for(int i = 0; i <= n; i++)
	{
		if(b[i].a1 > b[i].a2 && b[i].a1 > b[i].a3)
		{
			cnt++;
			sum += b[i].a1;
			if(cnt >= n/2)
			{
				continue;
			}
		}
		cnt = 0;
		if(b[i].a2 > b[i].a1 && b[i].a2 > b[i].a3)
		{
			cnt++;
			sum += b[i].a2;
			if(cnt >= n/2)
			{
				continue;
			}
		}
		cnt = 0;
		if(b[i].a2 > b[i].a1 && b[i].a2 > b[i].a3)
		{
			cnt++;
			sum += b[i].a3;
			if(cnt >= n/2)
			{
				continue;
			}
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
