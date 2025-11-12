#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
int A[10][10];
struct node{
	int val,people,club;
}score[300020];
bool visp[300020];
int cntc[10];
bool cmp(node a,node b)
{
	return a.val>b.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cnt=0;
		ans=0;
		memset(visp,0,sizeof(visp));
		memset(cntc,0,sizeof(cntc));
		cin>>n;
		if(n==2)
		{
			cin>>A[1][1]>>A[1][2]>>A[1][3]>>A[2][1]>>A[2][2]>>A[2][3];
			ans=max(ans,A[1][1]+max(A[2][2],A[2][3]));
			ans=max(ans,A[1][2]+max(A[2][1],A[2][3]));
			ans=max(ans,A[1][3]+max(A[2][1],A[2][2]));
			cout<<ans<<"\n";
			continue;
		}
		if(n==4)
		{
			cin>>A[1][1]>>A[1][2]>>A[1][3]>>A[2][1]>>A[2][2]>>A[2][3];
			cin>>A[3][1]>>A[3][2]>>A[3][3]>>A[4][1]>>A[4][2]>>A[4][3];
			ans=max(ans,A[1][1]+A[2][1]+A[3][2]+A[4][2]);
			ans=max(ans,A[1][1]+A[2][1]+A[3][2]+A[4][3]);
			ans=max(ans,A[1][1]+A[2][1]+A[3][3]+A[4][2]);
			ans=max(ans,A[1][1]+A[2][1]+A[3][3]+A[4][3]);
			ans=max(ans,A[1][1]+A[2][2]+A[3][1]+A[4][2]);
			ans=max(ans,A[1][1]+A[2][2]+A[3][1]+A[4][3]);
			ans=max(ans,A[1][1]+A[2][2]+A[3][2]+A[4][1]);
			ans=max(ans,A[1][1]+A[2][2]+A[3][2]+A[4][3]);
			ans=max(ans,A[1][1]+A[2][2]+A[3][3]+A[4][1]);
			ans=max(ans,A[1][1]+A[2][2]+A[3][3]+A[4][2]);
			ans=max(ans,A[1][1]+A[2][2]+A[3][3]+A[4][3]);
			ans=max(ans,A[1][1]+A[2][3]+A[3][1]+A[4][2]);
			ans=max(ans,A[1][1]+A[2][3]+A[3][1]+A[4][3]);
			ans=max(ans,A[1][1]+A[2][3]+A[3][2]+A[4][1]);
			ans=max(ans,A[1][1]+A[2][3]+A[3][2]+A[4][2]);
			ans=max(ans,A[1][1]+A[2][3]+A[3][2]+A[4][3]);
			ans=max(ans,A[1][1]+A[2][3]+A[3][3]+A[4][1]);
			ans=max(ans,A[1][1]+A[2][3]+A[3][3]+A[4][2]);
			ans=max(ans,A[1][2]+A[2][1]+A[3][1]+A[4][2]);
			ans=max(ans,A[1][2]+A[2][1]+A[3][1]+A[4][3]);
			ans=max(ans,A[1][2]+A[2][1]+A[3][2]+A[4][1]);
			ans=max(ans,A[1][2]+A[2][1]+A[3][2]+A[4][3]);
			ans=max(ans,A[1][2]+A[2][1]+A[3][3]+A[4][1]);
			ans=max(ans,A[1][2]+A[2][1]+A[3][3]+A[4][2]);
			ans=max(ans,A[1][2]+A[2][1]+A[3][3]+A[4][3]);
			ans=max(ans,A[1][2]+A[2][2]+A[3][1]+A[4][1]);
			ans=max(ans,A[1][2]+A[2][2]+A[3][1]+A[4][3]);
			ans=max(ans,A[1][2]+A[2][2]+A[3][3]+A[4][1]);
			ans=max(ans,A[1][2]+A[2][2]+A[3][3]+A[4][3]);
			ans=max(ans,A[1][2]+A[2][3]+A[3][1]+A[4][1]);
			ans=max(ans,A[1][2]+A[2][3]+A[3][1]+A[4][2]);
			ans=max(ans,A[1][2]+A[2][3]+A[3][1]+A[4][3]);
			ans=max(ans,A[1][2]+A[2][3]+A[3][2]+A[4][1]);
			ans=max(ans,A[1][2]+A[2][3]+A[3][2]+A[4][3]);
			ans=max(ans,A[1][2]+A[2][3]+A[3][3]+A[4][1]);
			ans=max(ans,A[1][2]+A[2][3]+A[3][3]+A[4][2]);
			ans=max(ans,A[1][3]+A[2][1]+A[3][1]+A[4][2]);
			ans=max(ans,A[1][3]+A[2][1]+A[3][1]+A[4][3]);
			ans=max(ans,A[1][3]+A[2][1]+A[3][2]+A[4][1]);
			ans=max(ans,A[1][3]+A[2][1]+A[3][2]+A[4][2]);
			ans=max(ans,A[1][3]+A[2][1]+A[3][2]+A[4][3]);
			ans=max(ans,A[1][3]+A[2][1]+A[3][3]+A[4][1]);
			ans=max(ans,A[1][3]+A[2][1]+A[3][3]+A[4][2]);
			ans=max(ans,A[1][3]+A[2][2]+A[3][1]+A[4][1]);
			ans=max(ans,A[1][3]+A[2][2]+A[3][1]+A[4][2]);
			ans=max(ans,A[1][3]+A[2][2]+A[3][1]+A[4][3]);
			ans=max(ans,A[1][3]+A[2][2]+A[3][2]+A[4][1]);
			ans=max(ans,A[1][3]+A[2][2]+A[3][2]+A[4][3]);
			ans=max(ans,A[1][3]+A[2][2]+A[3][3]+A[4][1]);
			ans=max(ans,A[1][3]+A[2][2]+A[3][3]+A[4][2]);
			ans=max(ans,A[1][3]+A[2][3]+A[3][1]+A[4][1]);
			ans=max(ans,A[1][3]+A[2][3]+A[3][1]+A[4][2]);
			ans=max(ans,A[1][3]+A[2][3]+A[3][2]+A[4][1]);
			ans=max(ans,A[1][3]+A[2][3]+A[3][2]+A[4][2]);
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			score[++cnt].val=x;
			score[cnt].people=i;
			score[cnt].club=1;
			score[++cnt].val=y;
			score[cnt].people=i;
			score[cnt].club=2;
			score[++cnt].val=z;
			score[cnt].people=i;
			score[cnt].club=3;
		}
		sort(score+1,score+cnt+1,cmp);
		for(int i=1;i<=cnt;i++)
			if(!visp[score[i].people]&&cntc[score[i].club]<n/2)
			{
				cntc[score[i].club]++;
				visp[score[i].people]=1;
				ans+=score[i].val;
			}
		cout<<ans<<"\n";
	}
}
