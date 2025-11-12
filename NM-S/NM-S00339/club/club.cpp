#include<bits/stdc++.h> 
using namespace std;
int n;
int main()
{	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,maxx,a43[110000],j;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int cnt=0,m1=0,m2=0,m3=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			int a1[j],a2[j],a3[j],a4[j],a42[j],a43[j],a41[j];
			cin>>a1[j]>>a2[j]>>a3[j];
			cnt+=max(a1[j],max(a2[j],a3[j]));
			if(a1[j]>a2[j]&&a1[j]>a3[j])
			{	m1++;
				a41[j]=a1[j]-max(a2[j],a3[j]);
			}
			else if(a2[j]>a3[j])
			{
				m2++;	
				a42[2]=a2[j]-max(a1[j],a3[j]);
			}
			else{
				m3++;
				a43[3]=a3[j]-max(a2[j],a1[j]);
			}
		
		}
		maxx=max(m1,max(m2,m3));
		if(maxx<=(n-2))
		cout<<cnt;
		else 
		{
		if(m1>m2&&m1>m3) 
			
			for(int l=1;l<=m1-(n/3);l++){
			cnt-=a43[1];
			}
		}cout<<cnt<<endl;
	
	}
	return 0;
}

