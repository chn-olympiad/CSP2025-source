#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],cnt=0;

int o(char c){
	if(c-'0'>=0&&c-'0'<=9){
		cnt++;
		return c-'0';
	}
	else return 0;
}
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<s.size();i++)
	{
		a[i]=o(s[i]);
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
