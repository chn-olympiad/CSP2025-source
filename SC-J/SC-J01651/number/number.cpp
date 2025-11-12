#include<bits/stdc++.h>
using namespace std;
char c;
map<int ,int> m; 
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	int n=s.size();
	for(int i=0;i<=9;i++)
		m[i]=0;
	for(int i=0;i<n;i++){
		c=s[i];
		if((c-'0')>=0&&(c-'0')<=9)
			m[(c-'0')]++;
	}
	for(int i=9;i>=0;i--)
		for(int j=0;j<m[i];j++)
			cout<<i;
	cout<<endl;
	return 0;
} 