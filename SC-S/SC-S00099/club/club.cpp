#include<bits/stdc++.h>
using namespace std;
int glad[205][4],n,ans,t;
int res[205],bumen[4],sec[205],gls[205];
void transfirst()
{
	cin>>n;
	for(int j=1;j<=n;j++) cin>>glad[j][1]>>glad[j][2]>>glad[j][3];
	for(int i=1;i<=n;i++)
	{
		if(glad[i][1]>glad[i][2])
			res[i]=1;
		else
			res[i]=2;
		if(glad[i][res[i]]<glad[i][3])
			res[i]=3;
		bumen[res[i]]++;
	}
	int sum1=0;
	for(int i=1;i<=n;i++)
	{
		sum1+=glad[i][res[i]];
	}
	ans=sum1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		transfirst();
		cout<<ans<<endl;
	}
	return 0;
}