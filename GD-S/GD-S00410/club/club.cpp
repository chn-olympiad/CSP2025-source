#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long a[5];
long long cha[5][100010],len[5],ans;
void solve(){
	len[1]=len[2]=len[3]=0;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cha[1][i]=cha[2][i]=cha[3][i]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[1]>>a[2]>>a[3];
		int max1,max2;
		if(a[1]>=a[2]&&a[2]>=a[3]) max1=1,max2=2;
		else if(a[1]>=a[3]&&a[3]>=a[2]) max1=1,max2=3;
		else if(a[2]>=a[1]&&a[1]>=a[3]) max1=2,max2=1;
		else if(a[2]>=a[3]&&a[3]>=a[1]) max1=2,max2=3;
		else if(a[3]>=a[1]&&a[1]>=a[2]) max1=3,max2=1;
		else if(a[3]>=a[2]&&a[2]>=a[1]) max1=3,max2=2;
//		cout<<max1<<" "<<max2<<'\n';
		ans+=a[max1];
		cha[max1][++len[max1]]=a[max1]-a[max2];
	}
	int maxi=0;
	for(int i=1;i<=3;i++) if(len[maxi]<len[i]) maxi=i;
//	cout<<len[maxi]<<" ";
	if(len[maxi]>(n/2))
	{
		sort(cha[maxi]+1,cha[maxi]+len[maxi]+1);
//		for(int i=1;i<=len[maxi];i++) cout<<cha[maxi][i]<<" ";
		for(int i=1;len[maxi]-i+1>n/2;i++)
		{
			ans-=cha[maxi][i];
		}
	}
	cout<<ans<<'\n';
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
} 
