#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3],b1,b2,b3;
int back(int w1,int w2,int w3,int num,int k)
{
	int ans=num,s1=0,s2=0,s3=0;
	if(k==n+1) return num;
	if(w1<b1) {
		s1=num+back(w1+1,w2,w3,a[k][0],k+1);
	}
	
	if(w2<b2) {
		s2=num+back(w1,w2+1,w3,a[k][1],k+1);
	}
	
	if(w3<b3) {
		s3=num+back(w1,w2,w3+1,a[k][2],k+1);
	}
	ans=max(s1,max(s2,s3));
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		b1=n/2;
		b2=n/2;
		b3=n/2;
		memset(a,0,sizeof(a));
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][0]>>a[j][1]>>a[j][2]; 
		}
		cout<<back(0,0,0,0,1)<<endl;
	}
	return 0;
}
