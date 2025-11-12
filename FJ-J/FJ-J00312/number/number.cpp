#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],ans=0;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x,tot=1,sum_0,v=1;
	for(int i=0;i<s.size();i++) {
		if(s[i]>'0'&&s[i]<='9') {
			a[i]=s[i]-48;
		}
		if(s[i]=='0') sum_0++;
	}
	sort(a,a+s.size());
	for(int i=1;i<=sum_0;i++) {
		v*=10;
	}
	for(int i=0;i<s.size();i++) 
		if(a[i]>0) {
			x=i;
			break;	
		}  
	int num=s.size()-x;
	for(int i=x;i<s.size();i++) {
		ans+=a[i]*tot;
		tot*=10;
	}
	cout<<ans*v;
	return 0;
}	 