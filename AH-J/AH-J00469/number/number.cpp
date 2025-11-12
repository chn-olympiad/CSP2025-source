#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-'0']++;
		}
	}
	if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0&&a[7]==0&&a[8]==0&&a[9]==0&&a[10]==0){
		cout<<0;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
