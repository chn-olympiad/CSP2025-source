#include<bits/stdc++.h>
using namespace std;
int a[100005];
int a1[100000]={};
int a2[100000]={};
int a3[100000]={};
int b[9] ={};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int q1,w1,e1,q2,w2,e2,ans[10000]={},q3,w3,e3,q4,w4,e4;
	for(int i=0;i<t;i++)
	{
		cin>>a[i];
		int x,c,v;
		if(a[i]==2)
		{
			cin>>q1>>w1>>e1>>q2>>w2>>e2;
			ans[0]=q1+w2;
			ans[1]=q1+e2;
			ans[2]=w1+q2;
			ans[3]=w1+e2;
			ans[4]=e1+q2;
			ans[5]=e1+w2;
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<5;j++)
				{
					if(ans[i]>ans[j])
					{
						swap(ans[i],ans[j]);
					}
				}
		}
		cout<<ans[0]<<endl;
		} 
		else if(a[i]==4)
		{
			cin>>q1>>w1>>e1>>q2>>w2>>e2>>q3>>w3>>e3>>q4>>w4>>e4;
			ans[0]=q1+q2+w3+w4;
			ans[1]=q1+q2+w3+e4;
			ans[2]=q1+q2+e3+w4;
			ans[3]=q1+q2+e3+e4;
			ans[4]=q1+q3+w2+w4;
			ans[5]=q1+q3+w2+e4;
			ans[6]=q1+q3+e2+w4;
			ans[7]=q1+q3+e2+e4;
			ans[8]=q1+q4+w3+w2;
			ans[9]=q1+q4+w3+e2;
			ans[10]=q1+q4+e3+w2;
			ans[11]=q1+q4+e3+e2;
			ans[12]=q3+q2+w1+w4;
			ans[13]=q3+q2+w1+e4;
			ans[14]=q3+q2+e1+w4;
			ans[15]=q3+q2+e1+e4;
			ans[16]=q4+q2+w3+w1;
			ans[17]=q4+q2+w3+e1;
			ans[18]=q4+q2+e3+w1;
			ans[19]=q4+q2+e3+e1;
			ans[20]=q3+q4+w1+w2;
			ans[21]=q3+q4+w1+e2;
			ans[22]=q3+q4+e1+w2;
			ans[23]=q3+q4+e1+e2;
			
			
			for(int i=0;i<35;i++)
			{
				for(int j=0;j<35;j++)
				{
					if(ans[i]>ans[j])
					{
						swap(ans[i],ans[j]);
					}
				}
			}
			cout<<ans[0]<<endl;
		} 
		else
		{
			for(int j=0;j<a[i];j++)
			{
				cin>>x>>c>>v;
				a1[j]=x;
				a2[j]=c;
				a3[j]=v;
			}
			for(int j=0;j<a[i];j++)
			{
				if(a1[j]<a2[j])
				{
					if(a2[j]<a3[j])
					{
						b[3]+=a3[j];
					 }
					 else
					 {
					 	b[2]+=a2[j];
					  } 
				}
				else
				{
					if(a1[j]<a3[j])
					{
						b[3]+=a3[j];
					 }
					 else
					 {
					 	b[1]+=a1[j];
					  } 
				}
			}
			cout<<b[1]+b[2]+b[3]<<endl;
		}
	}
		
	return 0;
}
