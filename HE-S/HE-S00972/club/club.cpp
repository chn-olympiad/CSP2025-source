#include<bits/stdc++.h>
using namespace std;
int n[60001][4]={},Dn=11000;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,club[4]={},a[6]={};
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		for(int i=1;i<=3;i++)
		{
			club[i]=0;
		}
		int num;
		cin>>num;
		for(int i=1;i<=num;i++)
		{
			int MemNum=i+Dn*(k-1);
			for(int j=1;j<=3;j++)
			{
				cin>>n[MemNum][j];
				n[MemNum][0]=MemNum;
			}
			int favorite=max(n[MemNum][1],max(n[MemNum][2],n[MemNum][3]));
			if(favorite==n[MemNum][1]&&club[1]<num/2)
			{
				club[1]++;
				if(n[MemNum-1][2]>n[MemNum-1][3]) n[MemNum-1][3]=0;
				else n[MemNum-1][2]=0;
			}
			else if(!(club[1]<num/2))
			{
				int *min,*min_f;
				min=&n[MemNum][1];
				min_f=&n[MemNum][0];
				for(int mem=1;mem<=i;mem++)
				{
					if(*min>n[MemNum-mem][1]&&n[MemNum-mem][1]!=0)
					{
						min=&n[MemNum-mem][1];
						min_f=&n[MemNum-mem][0];
					}
				}
				int change_2nd_fav=max(n[*min_f][2],n[*min_f][3]);
					if(change_2nd_fav==n[*min_f][2]&&club[2]<num/2)
						{
							club[2]++;
							if(n[MemNum-1][1]>n[MemNum-1][3]) n[MemNum-1][3]=0;
							else n[MemNum-1][1]=0;
						}
					else
					{
						if(!(club[2]<num/2))
						{
							int *min2,*min2_f;
							min2=&n[MemNum-1][1];
							min2_f=&n[MemNum-1][0];
							for(int mem=1;mem<=i;mem++)
							{
								if(*min2>n[MemNum-mem][2])
								{
									min2=&n[MemNum-mem][2];
									min2_f=&n[MemNum-mem][0];
								}
							}
								club[3]++;
								if(n[MemNum-1][2]>n[MemNum-1][2]) n[MemNum-1][2]=0;
								else n[MemNum-1][1]=0;
							*min=favorite;
						}
						else
						{
							club[3]++;
							if(n[MemNum-1][2]>n[MemNum-1][1]) n[MemNum-1][1]=0;
							else n[MemNum-1][2]=0;
						}
					}
				*min=favorite;
			}
			if(favorite==n[MemNum][2]&&club[2]<num/2)
			{
				club[2]++;
				if(n[MemNum-1][1]>n[MemNum-1][3]) n[MemNum-1][3]=0;
				else n[MemNum-1][1]=0;
			}
			else if(!(club[2]<num/2))
			{
				int *min,*min_f;
				min=&n[MemNum][2];
				min_f=&n[MemNum][0];
				for(int mem=1;mem<=i;mem++)
				{
					if(*min>n[MemNum-mem][2]&&n[MemNum-mem][2]!=0)
					{
						min=&n[MemNum-mem][2];
						min_f=&n[MemNum-mem][0];
					}
				}
				int change_2nd_fav=max(n[*min_f][1],n[*min_f][3]);
					if(change_2nd_fav==n[*min_f][1]&&club[1]<num/2)
					{
						club[1]++;
						if(n[MemNum-1][2]>n[MemNum-1][3]) n[MemNum-1][3]=0;
						else n[MemNum-1][2]=0;
					}
					else
					{
						if(!(club[1]<num/2))
						{
							int *min2,*min2_f;
							min2=&n[MemNum][1];
							min2_f=&n[MemNum][0];
							for(int mem=1;mem<=i;mem++)
							{
								if(*min2>n[MemNum-mem][1])
								{
									min2=&n[MemNum-mem][1];
									min2_f=&n[MemNum-mem][0];
								}
							}
								club[3]++;
								if(n[MemNum-1][2]>n[MemNum-1][1]) n[MemNum-1][1]=0;
								else n[MemNum-1][2]=0;
							*min=favorite;
						}
						else
						{
							club[3]++;
							if(n[MemNum-1][2]>n[MemNum-1][1]) n[MemNum-1][1]=0;
							else n[MemNum-1][2]=0;
						}
					}
				*min=favorite;
			}
			if(favorite==n[MemNum][3]&&club[3]<num/2)
			{
				club[3]++;
				if(n[MemNum-1][2]>n[MemNum-1][1]) n[MemNum-1][1]=0;
				else n[MemNum-1][2]=0;
			}
			else if(!(club[3]<num/2))
			{
				int *min,*min_f;
				min=&n[MemNum][2];
				min_f=&n[MemNum][0];
				for(int mem=1;mem<=i;mem++)
				{
					if(*min>n[MemNum-mem][3]&&n[MemNum-mem][3]!=0)
					{
						min=&n[MemNum-mem][3];
						min_f=&n[MemNum-mem][0];
					}
				}
				int change_2nd_fav=max(n[*min_f][1],n[*min_f][2]);
					if(change_2nd_fav==n[*min_f][1]&&club[1]<num/2)
					{
						club[1]++;
						if(n[MemNum-1][2]>n[MemNum-1][3]) n[MemNum-1][3]=0;
						else n[MemNum-1][2]=0;
					}
					else
					{
						if(!(club[1]<num/2))
						{
							int *min2,*min2_f;
							min2=&n[MemNum][1];
							min2_f=&n[MemNum][0];
							for(int mem=1;mem<=i;mem++)
							{
								if(*min2>n[MemNum-mem][1])
								{
									min2=&n[MemNum-mem][1];
									min2_f=&n[MemNum-mem][0];
								}
							}
								club[2]++;
								if(n[MemNum-1][3]>n[MemNum-1][1]) n[MemNum-1][1]=0;
								else n[MemNum-1][3]=0;
							*min=favorite;
						}
						else
						{
							club[2]++;
							if(n[MemNum-1][3]>n[MemNum-1][1]) n[MemNum-1][1]=0;
							else n[MemNum-1][3]=0;
						}
					}
				*min=favorite;
			}
			a[k]+=favorite;
		}
	}
	for(int i=1;i<=t;i++)
		cout<<a[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
