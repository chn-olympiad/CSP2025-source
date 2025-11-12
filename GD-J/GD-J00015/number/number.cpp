#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
	return int(a)>int(b); 
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	std::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	string s="";
	char x;
	while(cin>>x)
		if(x>='0'&&x<='9') s+=x;
	int q=s.size()-1;
	sort(s.begin(),s.begin()+q,cmp);
	int cnt=0;
	while(cnt<s.size()-1)
	{
		if(s[cnt]==0) cnt++;
		else break;
	}
	for(int i=cnt;i<s.size();i++) cout<<s[i];
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
