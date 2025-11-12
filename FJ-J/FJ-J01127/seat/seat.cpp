#include<bits/stdc++.h>
using namespace std;
int n,m,score[120],grade,ans1=1,ans2=1;
bool flag=1;
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>score[i];
	grade=score[1];
	sort(score+1,score+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(score[i]==grade)
		{
			cout<<ans1<<" "<<ans2;
			return 0;
		}
		else
		{
			if(flag)
				ans2++;
			else
				ans2--;
			if(ans2==n+1)
				ans1++,ans2=n,flag=0;
			if(ans2==0)
				ans1++,ans2=1,flag=1;
		} 
}
