#include<bits/stdc++.h>
using namespace std;

int n,m,R,ans_n,ans_m;
//set<int> a;
int a[105];


int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n, &m);
	int N=n*m;  //N为学生总数量
	int ai;
	for(int i=1; i<=N; i++)
	{
		cin>>ai;
		if(i==1)
		{
			R=ai;
		}
		//a.insert(ai);
		a[i]=ai;
	}
	sort(a+1,a+N+1,greater<int>());
	int r;
	for(int i=1;i<=N;i++)
	{
		if(a[i]==R)
		{
			r=i;
		}
	}
	int k=r/n;
	int b=r%n;
	//printf("R为%d K为%d B为%d\n",r,k,b);
	if(b==0)//b为0
	{
		if(k%2==0)//k为偶数
		{
			ans_n = 1;
		}
		else if(k%2==1)//k为奇数
		{
			ans_n = n;
		}
		ans_m = k;
	}
	else//b不为0
	{
		if(k%2==0)//k为偶数
		{
			ans_n = b;
		}
		else if(k%2==1)//k为奇数
		{
			ans_n = n+1-b;
		}
		ans_m = k+1;
	}
	printf("%d %d",ans_m, ans_n);
	return 0;
}
//4 7
//81 98 72 74 73 88 89 75 82 80 87 79 78 90 99 97 96 94 95 91 92 83 84 86 85 76 77 93
