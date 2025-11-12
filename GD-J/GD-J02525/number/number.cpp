#include<bits/stdc++.h>
using namespace std;
int num[1000005];
string s;
bool cmd(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size(),xb=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[++xb]=(int)(s[i]-'0');
		}
	}
	sort(num+1,num+1+xb,cmd);
	for(int i=1;i<=xb;i++) cout<<num[i];
	return 0;
}
