#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q;
string t1,t2,s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while (q--)
	{
		int cnt=0;
		cin>>t1>>t2;
		for (int i=1;i<=n;i++)
		{
			int d1=t1.find(s1[i]),d2=t2.find(s2[i]);
			if (d1<t1.size() && d2<t2.size() && d1==d2)
			{
				
				string s1_new=t1.substr(0,d1);
				s1_new+=s2[i];
				s1_new+=t1.substr(s1_new.size(),N);
//				string s1_new=t1;
//				int cur=0;
//				for (int j=d1;j<d1+s2[i].size();j++)
//					s1_new[j]=s2[i][cur++];
//					
				if (s1_new==t2)
				{
					cnt++;
//					cout<<'i'<<i<<endl;
				}
			}
		}
		
		cout<<cnt<<endl;
	}
//	cout<<t1.find("aa");
	return 0;
}
//			if (d1<t1.size() && d2<=t2.size() && d1==d2)
//			{
//				
//				
//			}




//for (int i=1;i<=n;i++)
//		{
//			int d1=t1.find(s1[i]);
//			int d2=t2.find(s2[i]);
//			string s1_new=s1[i].substr(0,d1);
//			s1_new+=t2;
//			s1_new+=s1[i].substr(s1_new.size(),N);
//			cout<<s1_new<<' '<<t2<<endl;
//			if (s1_new==t2) cnt++;
//		}
//		cout<<cnt<<endl;
//		cout<<74893<<endl;
