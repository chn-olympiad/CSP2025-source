#include<bits/stdc++.h>
using namespace std;
int n,q;
const int maxn =1e5+10;
string sa[maxn],sb[maxn];
string t1,t2;
int flag=0;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
    	cin>>sa[i]>>sb[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			int l,r;
			l=r=-1;
			int cnt=0;
			flag=0;
        for(int k=0;k<t1.size();k++)
        {
        	
        if(cnt<sa[i].size())
        	{
			if(sa[j][cnt]==t1[k]&&sb[j][cnt]==t2[k]) 
			{
	//			cout<<sa[j][cnt]<<" "<<sb[j][cnt]<<endl;
			//	cout<<l<<" "<<r<<endl;
				if(!flag)
				{
					flag=1; 
					l=k;
				}
				cnt++;
				if(cnt==sa[j].size()) r=k;
			//	cout<<cnt<<" "<<sa[j].size()<<" "<<l<<" "<<r<<endl;
			}
			else 
			{
				cnt=0;
				flag=0;
			}
		}
		}
		if(l==-1||r==-1) ans+=0;
		else{
			int ck=1;
			for(int ii=0;ii<l;ii++)
			{
				if(t1[ii]!=t2[ii]) 
				{
			//		cout<<ii<<" "<<t1[ii]<<" "<<t2[ii];
					ck=0;
				}
			}
			for(int ii=r+1;ii<t1.size();ii++)
			{
				if(t1[ii]!=t2[ii]) 
				{
				//	cout<<ii<<" "<<t1[ii]<<" "<<t2[ii];
					ck=0;
				}
			}
			ans+=ck;
		}
		//	cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
