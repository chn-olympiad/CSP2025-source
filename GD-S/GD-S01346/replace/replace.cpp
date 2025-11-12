#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][5],t1,t2,x,y,z;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	cout<<x[0]+y+z;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--)
	{
		long long ans=0;
		cin>>t1>>t2;
		int l=t1.size();
//		for(int i=1;i<=n;i++) 
//			if(s[i][1]==t1&&s[i][2]==t2) ans++;
		for(int i=0;i<l;i++)
			for(int j=i;j<l;j++)
			{
				x="",y="",z="";
				for(int k=0;k<i;k++) x+=t1[k];
				for(int k=i;k<=j;k++) y+=t1[k];
				for(int k=j+1;k<l;k++) z+=t1[k];
//				cout<<x<<' '<<y<<' '<<z<<endl;
				for(int k=1;k<=n;k++)
					if(y==s[k][1]&&x+s[k][2]+z==t2) 
					{
//					cout<<y<<' '<<x+s[k][2]+z<<endl;
						ans++;
					}
			}
		printf("%lld\n",ans);
	}
	return 0;
 } 
