# include <bits/stdc++.h>
using namespace std;
int Ans[10];string sg;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>sg;sg[sg.size()]=0;
	for(int i=0;sg[i];i++)
	if(sg[i]>='0' && sg[i]<='9')
	++Ans[(sg[i]-'0')];
	for(int i=9;i>=0;i--)
	while(Ans[i])cout<<i,--Ans[i];
	return 0;
}