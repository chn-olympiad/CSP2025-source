#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[999999],max=0,club[3]={0,0,0},an=0;
	cin >> t;
	cin >> n;
	for (int h = 0;h<t;h++)
	{
		for (int i = 0;i<n;i++)
		{
			for (int j = 0;j<3;j++)
			{
				cin >> a[3*i+j];
				if (club[j]<t/2)
				{
					if (max == 0)max = a[3*i+j];
					else if (max<a[3*i+j])max = a[3*i+j];
					club[j]+=1;
				}
				an+=max;
				max = 0;	
			}
		}
	}
	cout << an;	
	return 0;
}
