#include<bits/stdc++.h>
using namespace std;
int n;
int aa,bb,cc;
struct mu{
	int A,B,C;
} mu[100005];
int ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	for(int tt = 1;tt<=T;tt++)
	{
		cin >> n;
		for(int i = 0;i<n;i++)
		{
			cin >> mu[i].A>>mu[i].B>> mu[i].C;
		}
		for(int j = 0;j<= n;j++)
		{
			for(int i = 0;i<= n;i++)
			{
				if(mu[i+1].A+mu[i+1].C+mu[i+1].B>mu[i].A+mu[i].B+mu[i].C)
				{
					aa = mu[i+1].A;
					bb = mu[i+1].B;
					cc = mu[i+1].C;
					mu[i+1].A = mu[i].A;
					mu[i+1].B = mu[i].B;
					mu[i+1].C = mu[i].C;
					mu[i].A = aa;
					mu[i].B = bb;
					mu[i].C = cc;
				}
			}
		}
		aa = 0;
		bb = 0;
		cc =0;
		for(int i = 0;i<n;i++)
		{
			if(mu[i].A >= mu[i].B && mu[i].A>=mu[i].C) 
			{
				if((aa+1)*2 > n)
				{
					if(mu[i].B>=mu[i].C)
					{
						ans+=mu[i].B;
					}
					else if(mu[i].C>=mu[i].B)
					{
						ans+=mu[i].C;
					}
				}
				else{
					ans+=mu[i].A;
					aa++;
				}
					
			}
			else if(mu[i].B >= mu[i].A && mu[i].B>=mu[i].C)
			{
				if((bb+1)*2 > n)
				{
					if(mu[i].A>=mu[i].C)
					{
						ans+=mu[i].A;
					}
					else if(mu[i].C>=mu[i].A)
					{
						ans+=mu[i].C;
					}
				}
			else{
				ans+=mu[i].B;
				bb++;
			}
				
			}
			else if(mu[i].C >= mu[i].B && mu[i].C>=mu[i].A)
			{
				if((cc+1)*2 > n)
				{
					if(mu[i].B>=mu[i].A)
					{
						ans+=mu[i].B;
					}
					else if(mu[i].A>=mu[i].B)
					{
						ans+=mu[i].A;
					}
				}
				else{
					ans+=mu[i].C;
					cc++;
				}
				
			}
		}
		cout << ans << endl;
		ans = 0;
		aa = 0;
		bb = 0;
		cc = 0;
	}
	
	//for(int i = 0;i<n;i++)
	//{
	//	cout <<mu[i].A<<" "<<mu[i].B<<" "<< mu[i].C<<endl;
    //}
	return 0;
}
