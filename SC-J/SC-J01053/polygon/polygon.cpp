#include<bits/stdc++.h>
using namespace std;
#define int long long
int A[5005];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,m,t=0;
	cin>>n;
	m=n;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	sort(A+1,A+n+1);
	if(n==3)
	{
		int mx=INT_MIN,cnt=0;
		for(int i=1;i<=n;i++)
		{
			mx=max(mx,A[i]);
			cnt+=A[i];
		}
		if(cnt>2*mx)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		while(n--)
		{
			for(int i=1;i<=m-n;i++)
			{
				for(int j=i;j<=m-i;j++)
				{
					int mx=INT_MIN,cnt=0;
					for(int k=1;k<=j;k++)
					{
						mx=max(mx,A[k]);
						cnt+=A[k];
					}
					if(cnt>2*mx) t++;
					cout<<cnt<<" "<<mx<<endl;
				}
			}
		}
		cout<<t;
	}
	
	
	return 0;
}

//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);


/*
why can't I use Chinese???
就像这样 (其实是11:57才发现) 

shou wan gu zhe le hai lai kao CSP...
ji nian yi xia...
(shang ci CSP mei da freopen)

8:46
bushi
what this???
T1 is harder than T2 and T3 for me...

9:02
thanks for bao li
I AC(yes?) T1 for 30 min...
orz

9:05
xiao L guo bu liao di yi lun !!!
n*m<=100...?

9:26
It use 1.145 s.
I'm very tried.
I sleep at today 0:43...

9:30
T2 is very easy for me.
I want sleep!!!

9:49
em... 
ti kan cuo le
qwq

10:16
bushi
for(int i=1;i<=2;i++) wei sha zhi xun huan yi ci a?????

10:25
2%2!=0!!!

10:28
T2 AC(kan cuo ti ka le wo 1.5h)
"T2 is very easy for me."
zhi jie xie T4 ba(T3 xie bao li)

10:55
100+100+15+15(dan yuan ru ci)

11:41
em...
yao jie shu le...
jian cha yi xia freopen
Owo
T1 zhen mei da freopen

12:00
ti hao jian nan
dan fen shu xian ken ding heng gao
qwq
zhu da jia dou neng AK CSP

*/
//qing gan zhu luogu lyclyc868
//orz orz