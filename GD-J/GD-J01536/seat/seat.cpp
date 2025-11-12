#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
struct stu{
	int score,num;
}s[105];

int cmp(stu& a,stu& b)
{
	return a.score>b.score;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i].score;
		s[i].num=i;
	}
	sort(s+1,s+103,cmp);
	int seat=0;
	for(int i=1;i<=n*m;i++)
	{
		if(s[i].num==1)
		{
			seat=i;
			break;
		}
	}	
	if(seat%n==0)
	{
		c=seat/n;
	}
	else
	{
		c=seat/n+1;
	}
	
	if(c%2==0)
	{
		r=n+1-(seat-n*(c-1));
	}
	else{
		if(c==1)
		{
			r=seat;
		}
		else{
			r=seat-(n*(c-1));
		}
	}
	
	cout<<c<<" "<<r;
	fclose(stdin);fclose(stdout);
	return 0;
} 

