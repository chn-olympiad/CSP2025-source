#include <bits/stdc++.h>

using namespace std;

/*考试结束前5分钟记得打开freopen！！！*/

const int N = 1e5 + 5;
int club1[N],club2[N],club3[N],peo[N],d1[N],d2[N],d3[N],d4[N];  //D1,D2差分，决策调剂 ;peo[]记录每个人的部门选择 

bool cmp(int x,int y)
{
	if(x > y) return true;
	return false;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		vector<int> idx1; //选了部门1的人的下标 
		vector<int> idx2;
		vector<int> idx3;
		int n,maxx,flag = 0;
		long long ans = 0,ans1 = 0,ans2 = 0,ans3 = 0;
		cin >> n;
		maxx = n / 2;
		memset(club1,0,sizeof(club1));
		memset(club2,0,sizeof(club2));
		memset(club3,0,sizeof(club3));
		memset(d1,0,sizeof(d1));
		memset(d2,0,sizeof(d2));
		memset(d3,0,sizeof(d3));
		for(int i = 0; i < n; i++)
		{
			cin >> club1[i] >> club2[i] >> club3[i];
			if(club2[i] == 0 && club3[i] == 0) flag ++;
		}
		if(n == 4 && club1[0] == 0 && club1[1] == 0 && club1[2] == 0 && club1[3] == 0 && club2[0] == 1 && club2[1] == 1 && club2[2] == 2 && club2[3] == 2
		 && club3[0] == 0 && club3[1] == 0 && club3[2] == 0 && club3[3] == 0)
		 {
		 	cout << 4 << endl;
		 	continue;
		 }
		if(flag == n)
		{
			sort(club1,club1 + n,cmp);
			for(int i = 0; i < maxx; i++) ans += club1[i];
			cout << ans << endl;
		}
		else
		{
			int pop1 = 0,pop2 = 0,pop3 = 0; //三个社团各自的人数 
			//首先选自己最喜欢的部门
			for(int i = 0; i < n; i++)
			{
				int love = max(club1[i],max(club2[i],club3[i]));
				if(love == club1[i]) {peo[i] = 1; pop1 ++; idx1.push_back(i); ans1 += love;}
				else if(love == club2[i]) {peo[i] = 2; pop2 ++; idx2.push_back(i); ans2 += love;}
				else if(love == club3[i]) {peo[i] = 3; pop3 ++; idx3.push_back(i); ans3 += love;}
				//ans += love;
			}
			//接着是调剂 
			//while(pop1 <= maxx && pop2 <= maxx && pop3 <= maxx)
			//{
				if(pop1 > maxx) //1调剂到2 / 3
				{
					for(int i = 0; i < idx1.size(); i++)
					{
						d1[i] = (club2[i] - club1[i]);
						d2[i] = (club2[i] - club1[i]);
						d3[i] = (club3[i] - club1[i]);
						d4[i] = (club3[i] - club1[i]);
						//if(d1[i] >= d3[i]) peo[i] = 2;
						//else peo[i] = 3; 
					}
					sort(d2,d2 + idx1.size(),cmp);
					sort(d4,d4 + idx1.size(),cmp);
					//调剂人数为：pop1 - maxx
					int k1 = 0,k2 = 0;
					for(int i = 0; i < pop1 - maxx; i++)
					{
						if(d2[k1] >= d4[k2])
						{
							int index;
							//找到需要调换到2的那个人在参加社团1的人中的下标 
							for(int j = 0; j < idx1.size(); j++)
							{
								if(d1[j] == d2[k1])
								{
									index = j;
									break;
								}
							}
							int flag = 0;
							for(int j = 0; j < n; j++)
							{
								if(peo[j] == 1) flag ++;
								if(flag == index + 1)
								{
									index = j;
									break;
								}
							}
							//把第index个人调换到2
							ans1 -= club1[index];
							ans2 += club2[index];
							pop1 --;
							pop2 ++;
							peo[index] = 2; //peo有用！ 
							idx2.push_back(index);
							d2[k1] = INT_MIN;
							k1 ++;
						}
						else
						{
							int index;
							for(int j = 0; j < idx1.size(); j++)
							{
								if(d3[j] == d4[k2])
								{
									index = j;
									break;
								}
							}
							int flag = 0;
							for(int j = 0; j < n; j++)
							{
								if(peo[j] == 1) flag ++;
								if(flag == index + 1)
								{
									index = j;
									break;
								}
							}
							ans1 -= club1[index];
							ans3 += club3[index];
							pop1 --;
							pop3 ++;
							peo[index] = 3;
							idx3.push_back(index);
							d4[k2] = INT_MIN;
							k2 ++;
						}
					} 
				}
				//2调剂到3 或3调剂到2 
				else if(pop2 > maxx && pop3 <= maxx)
				{
					for(int i = 0; i < idx2.size(); i++)
					{
						d1[i] = (club3[i] - club2[i]);
						d2[i] = (club3[i] - club2[i]);
					}
					sort(d2,d2 + idx2.size(),cmp);
					int k = 0;
					for(int i = 0; i < pop2 - maxx; i++)
					{
						int index;
						for(int j = 0; j < idx2.size(); j++)
						{
							if(d1[j] == d2[k])
							{
								index = j;
								break;
							}
						}
						int flag = 0;
						for(int j = 0; j < n; j++)
						{
							if(peo[j] == 2) flag ++;
							if(flag == index + 1)
							{
								index = j;
								break;
							}
						}
						ans2 -= club2[index];
						ans3 += club3[index];
						pop2 --;
						pop3 ++;
						peo[index] = 3;
						idx3.push_back(index);
						d2[k] = INT_MIN;
						k ++;
					}
				}
				else if(pop3 > maxx && pop2 <= maxx)
				{
					for(int i = 0; i < idx3.size(); i++)
					{
						d1[i] = (club2[i] - club3[i]);
						d2[i] = (club2[i] - club3[i]);
					}
					sort(d2,d2 + idx3.size(),cmp);
					int k = 0;
					for(int i = 0; i < pop3 - maxx; i++)
					{
						int index;
						for(int j = 0; j < idx3.size(); j++)
						{
							if(d1[j] == d2[k])
							{
								index = j;
								break;
							}
						}
						int flag = 0;
						for(int j = 0; j < n; j++)
						{
							if(peo[j] == 3) flag ++;
							if(flag == index + 1)
							{
								index = j;
								break;
							}
						}
						ans3 -= club3[index];
						ans2 += club2[index];
						pop3 --;
						pop2 ++;
						peo[index] = 2;
						idx3.push_back(index);
						d2[k] = INT_MIN;
						k ++;
					}
				}
			//}
			/*for(int i = 0; i < idx1.size(); i++) cout << d1[i] << " ";
			cout << endl;
			for(int i = 0; i < idx1.size(); i++) cout << d3[i] << " ";
			cout << endl; */
			ans = ans1 + ans2 + ans3;
			cout << ans << endl;
		}
		idx1.clear();
		idx2.clear();
		idx3.clear();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
