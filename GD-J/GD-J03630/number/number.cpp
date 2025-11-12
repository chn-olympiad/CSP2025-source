#include<bits/stdc++.h>
using namespace std;
int Num[10],Ans[1000005];
string S;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int Len,Len2=0;
	cin>>S;
	Len=S.size();
	for(int i=0;i<Len;i++)
		if(S[i]>='0'&&S[i]<='9')
			Num[S[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(Num[i]>0)
		{
			Len2++;
			Ans[Len2]=i;
			Num[i]--;
		}
	for(int i=1;i<=Len2;i++)
		cout<<Ans[i];
	return 0;
}
