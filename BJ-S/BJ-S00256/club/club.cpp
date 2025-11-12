#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll t,n,ans;
int q[5];//部门人数

struct node
{
	int s1,s2,s3,bel;//对各部好感  现属部
}a[N];

bool cmp1(node n1,node n2)//从s1移至其他部亏损
{
	return min(n1.s1-n1.s2,n1.s1-n1.s3)<min(n2.s1-n2.s2,n2.s1-n2.s3);//按移动亏损从小到大 移动亏损:min(s1-s2,s1-s3)
}
bool cmp2(node n1,node n2)//从s2移至其他部亏损
{
	return min(n1.s2-n1.s1,n1.s2-n1.s3)<min(n2.s2-n2.s1,n2.s2-n2.s3);//按移动亏损从小到大 移动亏损:min(s1-s2,s1-s3)
}
bool cmp3(node n1,node n2)//从s3移至其他部亏损
{
	return min(n1.s3-n1.s1,n1.s3-n1.s2)<min(n2.s3-n2.s1,n2.s3-n2.s2);//按移动亏损从小到大 移动亏损:min(s1-s2,s1-s3)
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		q[1]=0,q[2]=0,q[3]=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			int mx=max(a[i].s1,max(a[i].s2,a[i].s3));
			if(mx==a[i].s1) {q[1]++;a[i].bel=1;}
			else if(mx==a[i].s2) {q[2]++;a[i].bel=2;}
			else {q[3]++;a[i].bel=3;}//统计部门人数 所属部门 部门总好感度
		}
		while(q[1]>n/2 || q[2]>n/2 || q[3]>n/2)//部门数不符合要求时
		{
			if(q[1]>n/2)
			{
				sort(a+1,a+n+1,cmp1);
				int cnt=q[1]-n/2;
				for(int i=1; i<=n; i++)//将超出部分移走
				{
					if(a[i].bel!=1) continue;
					if(cnt<=0) break;
					if((a[i].s1-a[i].s2)==(a[i].s1-a[i].s3))//优先选择人数少的部门
					{
						if(q[2]<q[3])
						{
							a[i].bel=2;
							q[1]--;
							q[2]++;
						}else
						{
							a[i].bel=3;
							q[1]--;
							q[3]++;
						}
						cnt--;
						continue;
					}
					
					if((a[i].s1-a[i].s2)>(a[i].s1-a[i].s3))//选择亏损少的部门
					{
						a[i].bel=3;
						q[1]--;
						q[3]++;
					}else
					{
						a[i].bel=2;
						q[1]--;
						q[2]++;
					}
					cnt--;
				}
			}else if(q[2]>n/2)
			{
				sort(a+1,a+n+1,cmp2);
				int cnt=q[2]-n/2;
				for(int i=1; i<=n; i++)//将超出部分移走
				{
					if(a[i].bel!=2) continue;
					if(cnt<=0) break;
					if((a[i].s2-a[i].s3)==(a[i].s2-a[i].s1))//优先选择人数少的部门
					{
						if(q[3]<q[1])
						{
							a[i].bel=3;
							q[2]--;
							q[3]++;
						}else
						{
							a[i].bel=1;
							q[2]--;
							q[1]++;
						}
						cnt--;
						continue;
					}
					
					if((a[i].s2-a[i].s3)>(a[i].s2-a[i].s1))
					{
						a[i].bel=1;
						q[2]--;
						q[1]++;
					}else
					{
						a[i].bel=3;
						q[2]--;
						q[3]++;
					}
					cnt--;
				}
			}else
			{
				sort(a+1,a+n+1,cmp3);
				int cnt=q[3]-n/2;
				for(int i=1; i<=n; i++)//将超出部分移走
				{
					if(a[i].bel!=3) continue;
					if(cnt<=0) break;
					if((a[i].s3-a[i].s1)==(a[i].s3-a[i].s2))//优先选择人数少的部门
					{
						if(q[1]<q[2])
						{
							a[i].bel=1;
							q[3]--;
							q[1]++;
						}else
						{
							a[i].bel=2;
							q[3]--;
							q[2]++;
						}
						cnt--;
						continue;
					}
					
					if((a[i].s3-a[i].s1)>(a[i].s3-a[i].s2))
					{
						a[i].bel=2;
						q[3]--;
						q[2]++;
					}else
					{
						a[i].bel=1;
						q[3]--;
						q[1]++;
					}
					cnt--;
				}
			}
		}
		//统计
		for(int i=1;i<=n;i++)
		{
			if(a[i].bel==1)//属于1部门
			{
				ans+=a[i].s1;
			}else if(a[i].bel==2)//属于2部门
			{
				ans+=a[i].s2;
			}else//属于3部门
			{
				ans+=a[i].s3;
			}
		}		
		cout<<ans<<endl;
	}
	return 0;
}
