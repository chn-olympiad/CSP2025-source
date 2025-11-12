#include<bits\stdc++.h>
using namespace std;
const int N=1e6+10;
int s1[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=0;
	for(char a:s)
	{
		if(a-'0'<10&&a-'0'>=0)
		{
			n++;
			s1[n]=a-'0'; 
		}
	}
	sort(s1+1,s1+n+1);
	for(int i=n;i>=1;i--)
	{
		cout<<s1[i];
	}
	return 0;
} 
