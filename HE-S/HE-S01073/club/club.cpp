#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Student
{
	int a,b,c;
}stu[100005];
int n;
int ans;

bool cmp(Student s1,Student s2)
{
	return s1.a>s2.a;
}


void DFS(int a,int b,int c,int cur,int cur_ans)
{
	
	if(cur>n)
	{
		ans=max(ans,cur_ans);
		return ;
	}
	if(a-1>=0)
		DFS(a-1,b,c,cur+1,cur_ans+stu[cur].a);
	if(b-1>=0)
		DFS(a,b-1,c,cur+1,cur_ans+stu[cur].b);
	if(c-1>=0)
		DFS(a,b,c-1,cur+1,cur_ans+stu[cur].c);
	//return max(max(DFS(a-1,b,c,cur+1)+stu[cur].a,DFS(a,b-1,c,cur+1))+stu[cur].b,DFS(a,b,c-1,cur+1)+stu[cur].c);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	bool f=true;
	scanf("%d",&t);
	while(t--)
	{
		memset(stu,0,sizeof stu);
		scanf("%d",&n);
		ans=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
			if(stu[i].b==stu[i].c==0)
			{
				f=false;
			}
		}
		if(!f)
		{
			sort(stu+1,stu+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=stu[i].a;
			}
		}
		else
			DFS(n/2,n/2,n/2,1,0);
		printf("%d\n",ans);
	}
/*
3
2
10 9 8
4 0 0
*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}

