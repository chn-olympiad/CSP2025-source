#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;
int t,r,n,d1[MAXN],d2[MAXN],d3[MAXN];
int del1[MAXN],del2[MAXN],del3[MAXN],p1,p2,p3;
long long ans;

int main()
{
	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		ans=0,p1=0,p2=0,p3=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>d1[i]>>d2[i]>>d3[i];
			     if(d1[i]>=d2[i]&&d2[i]>=d3[i]) ans+=d1[i],del1[i]=d1[i]-d2[i],p1++;
			else if(d1[i]>=d3[i]&&d3[i]>=d2[i]) ans+=d1[i],del1[i]=d1[i]-d3[i],p1++;
			else if(d2[i]>=d1[i]&&d1[i]>=d3[i]) ans+=d2[i],del2[i]=d2[i]-d1[i],p2++;
			else if(d2[i]>=d3[i]&&d3[i]>=d1[i]) ans+=d2[i],del2[i]=d2[i]-d3[i],p2++;
			else if(d3[i]>=d1[i]&&d1[i]>=d2[i]) ans+=d3[i],del3[i]=d3[i]-d1[i],p3++;
			else                                ans+=d3[i],del3[i]=d3[i]-d2[i],p3++;
		}
		
		if((p1<=n/2)&&(p2<=n/2)&&(p3<=n/2)){
			cout<<ans<<endl;
			continue;
		}
		else{
			sort(del1,del1+p1-1);
			sort(del2,del2+p2-1);
			sort(del3,del3+p3-1);
			int h=max(p1,max(p2,p3))-n/2;
			if(p1>p2&&p1>p3)
			    for(int i=0;i<h;i++)
			        ans-=del1[i];
			if(p2>p1&&p2>p3)
			    for(int i=0;i<h;i++)
			        ans-=del2[i];
			if(p3>p2&&p3>p1)
			    for(int i=0;i<h;i++)
			        ans-=del3[i];
			
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
