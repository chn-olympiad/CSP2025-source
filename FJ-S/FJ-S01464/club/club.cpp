#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int num = 1e5+10;
int a[num][4];
int t,n;
ll sum_answer[num];
vector<int> ans1,ans2,ans3;//ans从0开始 

//条件：l18 ,压如到返回的位数 ,从小到大 
int zipush_in(int tar_num,int club_num,int start_num,int end_num)  //tar_num为要存入的同学序号 ，a,ans全局 
{
	if (end_num - start_num == 1) //迭代最终 
	{
		if (a[tar_num][club_num] > a[end_num][club_num])
			return (end_num+1);
		else if (a[tar_num][club_num] < a[end_num][club_num]){return start_num;}
			else return end_num;
	}
	else
	{
		if (a[tar_num][club_num] == a[start_num][club_num]) return start_num;
		else if (a[tar_num][club_num] == a[end_num][club_num]) return (end_num+1);
		else
		{
			if (a[tar_num][club_num] > a[(start_num+end_num)/2][club_num])
			{
				return (zipush_in(tar_num,club_num,(start_num+end_num)/2,end_num));
			}
			else return (zipush_in(tar_num,club_num,end_num,(start_num+end_num)/2));
		}
//		if (a[tar_num] > a[start_num]) && (a[tar_num] > a[start_num])
	}
}

void zisort(int n,int s_tur)  //s_tur 为社团, 
{
	if (s_tur == 1)
	{
	//	int ans[num],ans_tur =1;
		for(int zi=1;zi<=n;zi++)
		{
			int temp1=0,temp2=0;
	//		if (a[zi][s_tur] > a[zi+1][s_tur])  //zi同学编号 都要排序 
	//		{
	//			if (ans.size() <= n/2)
	//			{
			int pos = zipush_in(zi,s_tur,0,ans1.size());
			if(pos > ans1.size()) //zhijieya
				ans1.push_back(zi);
			else
			{
				temp1 = ans1[pos];
				ans1[pos] = zi;
				for(int zj=pos;zj<ans1.size();zj++)//push
				{
					if (temp1!=0)
					{
						temp2=ans1[zj+1];
						ans1[zj+1] = temp1;
						temp1=0; 
					}
					else
					{
						temp1=ans1[zj+1];
						ans1[zj+1]=temp2;
						temp2=0;
					} 
				}					
			}
		}
	}
	else if (s_tur == 2)
	{

		for(int zi=1;zi<=n;zi++)
		{
			int temp1=0,temp2=0;
					int pos = zipush_in(zi,s_tur,0,ans2.size());
					if(pos > ans2.size()) //zhijieya
						ans2.push_back(zi);
					else
					{
						temp1 = ans2[pos];
						ans2[pos] = zi;
						for(int zj=pos;zj<ans2.size();zj++)//push
						{
							if (temp1!=0)
							{
								temp2=ans2[zj+1];
								ans2[zj+1] = temp1;
								temp1=0; 
							}
							else
							{
								temp1=ans2[zj+1];
								ans2[zj+1]=temp2;
								temp2=0;
							} 
						}					
					}
	
		}
	} 
	else if (s_tur == 3)
	{

		for(int zi=1;zi<=n;zi++)
		{
			int temp1=0,temp2=0;
					int pos = zipush_in(zi,s_tur,0,ans3.size());
					if(pos > ans3.size()) //zhijieya
						ans3.push_back(zi);
					else
					{
						temp1 = ans3[pos];
						ans3[pos] = zi;
						for(int zj=pos;zj<ans3.size();zj++)//push
						{
							if (temp1!=0)
							{
								temp2=ans3[zj+1];
								ans3[zj+1] = temp1;
								temp1=0; 
							}
							else
							{
								temp1=ans3[zj+1];
								ans3[zj+1]=temp2;
								temp2=0;
							} 
						}					
					}
	
		}
	}
		 
}

int compare()
{
	ll ans_count=0;
	for (int zci=1;zci <= max(ans1.size(),max(ans3.size(),ans2.size()));zci++) 
	{
		if ((ans1[zci] != ans2[zci])&&(ans2[zci] != ans3[zci]))
			ans_count = ans_count + a[ans1[zci]][1] + a[ans2[zci]][2] + a[ans3[zci]][1];
		else
		{
			if (ans1[zci] == ans2[zci])
			{
				if (ans2[zci] == ans3[zci])
				{
					ans_count += max(a[ans1[zci]][1],max(a[ans2[zci]][2],a[ans3[zci]][1]));
//					continue;
				}
				else
				{
					ans_count = max(a[ans1[zci]][1],a[ans2[zci]][2]) + ans_count + a[ans3[zci]][1];
				} 
			}
			
			
			else if (ans1[zci] == ans3[zci])
			{
				ans_count = max(a[ans1[zci]][1],a[ans2[zci]][3]) + ans_count + a[ans3[zci]][2];	
			}
		}		
	}

	return ans_count;	
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		memset(a[1],0,sizeof(a[1]));
		memset(a[2],0,sizeof(a[1]));
		memset(a[3],0,sizeof(a[1]));
		
		for (int cli=1;cli<=ans1.size();cli++)
			ans1.pop_back();
		for (int cli=1;cli<=ans2.size();cli++)
			ans2.pop_back();
		for (int cli=1;cli<=ans3.size();cli++)
			ans3.pop_back();
		int n=0;
		cin >> n;
		for(int j=1;j<=n;j++) 
			for(int k=1;k<=3;k++)
		 		cin >> a[j][k];
		for(int j=1;j<=3;j++)
			zisort(n,j);
		sum_answer[i] = compare();
//		sort()
		
	}
	
	for(int i=1;i<=t;i++)
	{
		cout << sum_answer[i];
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
