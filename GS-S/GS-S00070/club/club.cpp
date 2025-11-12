#include <bits/stdc++.h>
using namespace std; 

int zshu;
int zz=0;
int q[15];
int w;
int jg;




int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> zshu;
	for (int i=1;i<=zshu;i++)
	{
		cin >> zz;
		jg = 0;
		for (int j=1;j<=zz;j++)
		{
			cin >> q[1]>>q[2]>>q[3];
			w = max({q[1],q[2],q[3]});
			if (w=q[1])
			{
				jg=jg+q[1];
			}
			if (w=q[2])
			{
				jg=jg+q[2];
			}
			if (w=q[3])
			{
				jg=jg+q[3];
			}	
		}
		cout << jg;
	}
	
	
	
	
	
	return 0;
}
