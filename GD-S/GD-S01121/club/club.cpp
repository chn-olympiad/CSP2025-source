#include<bits/stdc++.h>
using namespace std;
int t,n,s[900],a[100005][5],st[100005],cd[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;while(t--){
	s[1]=0,s[2]=0,s[3]=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=max(a[i][2],a[i][3]))st[i]=1,s[1]++,cd[s[1]][1]=a[i][1]-max(a[i][2],a[i][3]);
		else if(a[i][2]>=max(a[i][1],a[i][3]))st[i]=2,s[2]++,cd[s[2]][2]=a[i][2]-max(a[i][1],a[i][3]);
		else st[i]=3,s[3]++,cd[s[3]][3]=a[i][3]-max(a[i][2],a[i][1]);
	}int mor=0;
	if(s[1]>n/2)mor=1;
	if(s[2]>n/2)mor=2;
	if(s[3]>n/2)mor=3;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i][st[i]];
	}
	if(!mor)cout<<sum<<endl;
	else {
	int cdf[114514];
	for(int i=1;i<=s[mor];i++)
	cdf[i]=cd[i][mor];
	sort(cdf+1,cdf+s[mor]+1);
	for(int i=1;i<=s[mor]-n/2;i++)
	sum-=cdf[i];
	cout<<sum<<endl;
	}
	}return 0;
} 
