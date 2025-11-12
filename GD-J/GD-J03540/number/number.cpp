#include<bits/stdc++.h>
using namespace std;
string s;
int v[15];
bool sb=false;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			v[int(s[i]-'0')]++;
			if(int(s[i]-'0')!=0) sb=true;
		}
	}
	if(!sb)
	{
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=v[i];j++)
		{
			cout<<i;
		}
	}
	//cout<<"\n"<<v[0];
	
	return 0;
}
//#Shang4Shan3Ruo6Shui4
