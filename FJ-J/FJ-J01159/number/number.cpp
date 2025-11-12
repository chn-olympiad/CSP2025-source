#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	//cout<<s[0];
	int l=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1') {
			a[l++]=1;continue;
		}else if(s[i]=='2')
		{
			a[l++]=2;continue;
		}else if(s[i]=='3')
		{
			a[l++]=3;continue;
		}else if(s[i]=='4')
		{
			a[l++]=4;continue;
		}else if(s[i]=='5')
		{
			a[l++]=5;continue;
		}else if(s[i]=='6')
		{
			a[l++]=6;continue;
		}else if(s[i]=='7')
		{
			a[l++]=7;continue;
		}else if(s[i]=='8')
		{
			a[l++]=8;continue;
		}
		 else if(s[i]=='9')
		{
			a[l++]=9;continue;
		}else if(s[i]=='0')
		{
			a[l++]=0;continue;
		}
		
	}
	//cout<<a[1];
	sort(a,a+l);
	
	//cout<<l;
	for(int i=l-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
	
}
