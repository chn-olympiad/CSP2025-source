#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0;
int vm,vt,a1,a2,a3;
struct
{
	int m1,m2,m3;
	int val;
}v[100005];
//int valuedelta(int a,int b,int c,int wz)
//{
//	int ans[5]={0,0,0,0,0};
//	ans[1]=a;
// 	ans[2]=b;
//	ans[3]=c;
//	return ans[wz]-max(a,max(b,c));
//}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int I=1;I<=t;I++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i].m1>>v[i].m2>>v[i].m3;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=n;j++)
			{
				if(v[i].m1>v[i-1].m1)swap(v[i].m1,v[i-1].m1);
			}
		}
		for(int i=1;i<=n;i++)cout<<v[i].m1<<" ";
		cout<<endl;
		for(int i=1;i<=n/2;i++)ans=ans+v[i].m1;
//		cout<<ans;
//		for(int i=1;i<=n;i++)
//		{
//			if(v[n].m1=max(v[n].m1,max(v[n].m2,v[n].m3)))
//			{
//				v[i].val=valuedelta(v[i].m1,v[i].m2,v[i].m3,1);
//				sort(v.val+1,v.val+1+n);
//				
//				
//			}
//		}
		 cout<<0;
	}
	return 0;
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 //Ren5Jie4Di4Ling5%
