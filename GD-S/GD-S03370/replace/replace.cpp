#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,Q,L[N],R[N];
string stra[N],strb[N];
//1:1~l,2:l~r,3:r~n
int main()
{
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>Q;
	//bool flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>stra[i]>>strb[i];
		L[i]=0,R[i]=int(stra[i].size())-1;
		while(L[i]<=R[i]&&stra[i][L[i]]==strb[i][L[i]]) L[i]++;
		while(L[i]<=R[i]&&stra[i][R[i]]==strb[i][R[i]]) R[i]--;
//		bool flag2=0,flag3=0;
//		for(int j=0;j<int(stra[i].size());j++)
//		{
//			if(stra[i][j]!='a'&&(stra[i][j]!='b'||flag2)) flag=1;
//			if(strb[i][j]!='a'&&(strb[i][j]!='b'||flag3)) flag=1;
//			if(stra[i][j]=='b') flag2=1;
//			if(strb[i][j]=='b') flag3=1;
//		}
		//printf("%d %d\n",L[i],R[i]);
	}
//	if(!flag)
//	{
//		while(Q--)
//		{
//			string str1,str2;
//			cin>>str1>>str2;
//			if(str1.size()!=str2.size())
//			{
//				printf("0\n");
//				continue;
//			}
//			int ;
//		}
//		return 0;
//	}
	while(Q--)
	{
		string str1,str2;
		cin>>str1>>str2;
		if(str1.size()!=str2.size())
		{
			cout<<"0\n";
			continue;
		}
		int l=0,r=int(str1.size())-1;
		while(l<=r&&str1[l]==str2[l]) l++;
		while(l<=r&&str1[r]==str2[r]) r--;
		int ans=0;
		//printf("%d %d\n",l,r);
		for(int i=1;i<=n;i++)
		{
			int sum1=str1.size()-r,sum2=stra[i].size()-R[i];
			if(l<L[i]||sum1<sum2||r-l!=R[i]-L[i]) continue;
			//printf("it1 : %d\n",i);
			if(str1.substr(l-L[i],L[i])!=stra[i].substr(0,L[i])) continue;
			if(str1.substr(r+1,sum2-1)!=stra[i].substr(R[i]+1,sum2-1)) continue;
			//printf("it2 : %d\n",i);
			if(str1.substr(l,r-l+1)!=stra[i].substr(L[i],R[i]-L[i]+1)) continue;
			if(str2.substr(l,r-l+1)!=strb[i].substr(L[i],R[i]-L[i]+1)) continue;
			//printf("%d\n",i);
			ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
