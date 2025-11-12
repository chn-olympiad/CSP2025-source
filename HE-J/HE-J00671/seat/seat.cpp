#include <bits/stdc++.h>
using namespace std;
int score[101];
int n,m,sc,sumnum,rank,ansn,ansm;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; sumnum=n*m;
	for(int i=1;i<=sumnum;i++) cin>>score[i];
	
	sc=score[1];
	sort(score+1,score+sumnum+1);
	for(int i=1;i<=sumnum;i++)
	{
		if(score[i]==sc) rank=sumnum-i+1;
	}
	
	if(rank%n==0)
	{
		ansm=rank/n;
		if((rank/n)%2==0) ansn=1;
		else ansn=n;
	}
	else if(rank%n!=0)
	{
		ansm=rank/n+1;
		if((rank/n+1)%2==0) ansn=n-(rank%n)+1;
		else ansn=rank%n;
	}
	cout<<ansm<<" "<<ansn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
