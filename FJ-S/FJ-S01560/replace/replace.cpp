#include<bits/stdc++.h>
using namespace std;
map<string,string> d;
int main()
{
	freopen("replace.in","r",stdin);
 	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		d[s1]=s2;
	}
	for(int i=1;i<=q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			cout<<0<<endl;
			continue;
		}
		string diff1,diff2;
		int ld,rd;
		int f=0;
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]!=s2[i]&&f==0)
			{
				f=1;
				ld=i;
			}
			if(f==1)
			{
				diff1+=s1[i];
				diff2+=s2[i];
			}
		}
//		cout<<1111<<endl;
		if(f!=0)
		{
			int kk=diff1.size()-1;
			while(diff1[kk]==diff2[kk])
			{
				diff1.erase(kk);
				diff2.erase(kk);
				kk--;
			}
//			cout<<"kk = "<<kk<<endl;
			rd=ld+kk;
		}
//		string tmp;
//		for(int i=2;i<=3;i++)tmp+=s1[i];
//		cout<<tmp<<endl;
//		cout<<ld<<endl<<rd<<endl;
		int diffsize=diff1.size();
//		cout<<diffsize<<endl;
		int ans=0;
//		int cnt1=0,cnt2=0;
		for(int i=ld;i>=0;i--)
		{
			for(int j=rd;j<s1.size();j++)
			{
				string sub1,sub2;
				for(int k=i;k<=j;k++)
				{
					sub1+=s1[k];
					sub2+=s2[k]; 
				}
//				cout<<sub1<<endl<<sub2<<endl;
				if(d[sub1]==sub2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

