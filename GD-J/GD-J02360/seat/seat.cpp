#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 100 + 42;

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int score[MAXN];
	
	int n,m;
	cin>>n>>m;
	int t = n * m;
	for(int i = 0;i < t;i++)
	{
		cin>>score[i];
	}
	
	int scr = score[0];
	
	sort(score,score + t,cmp);
	
	
	int paiming = 0;
	for(int i = 0;i < t;i++)
	{
		if(score[i] == scr)
		{
			paiming = i + 1;
			break;
		}
	}
	int c = paiming / n;
	if(paiming % n)c++;
	
	int r = paiming % n ;
	if(c % 2 == 0)
	{
		r = n - r + 1;
	}
	if(r == 0)r = n;
	
	cout<<c<<" "<<r<<endl;
	
	return 0;
}
