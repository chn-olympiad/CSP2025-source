#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>=b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,l,h;
	bool ud=true;    //down-true,up-false
	cin>>n>>m;
	int sts=n*m;
	vector<int> seat;
	for(int i=0;i<sts;i++)
	{
		int score;
		cin>>score;
		seat.push_back(score);
	}
	r=seat[0];
	sort(seat.begin(),seat.end(),cmp);
	h=0;l=1;
	for(int i=0;i<sts;i++)
	{
		h+=(ud?1:-1);
		if(h>n)
		{
			ud=!ud;
			l++;
			h=n;
		}
		else if(h<=0)
		{
			ud=!ud;
			l++;
			h=1;
		}
		if(seat[i]==r)
		{
			cout<<l<<" "<<h;
		}
	}
	return 0;
}
