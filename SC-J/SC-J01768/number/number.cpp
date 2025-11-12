#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[N];
	int idx=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		char c=s[i];
		if(c>='0'&&c<='9') a[idx++]=c;
	}
	sort(a+0,a+idx,cmp);
	for(int i=0;i<idx;i++) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 