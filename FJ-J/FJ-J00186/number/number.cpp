#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
char a[1000010];
ll sum,l;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	
	l=s.size();
	
	for(ll i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++sum]=s[i];
		}
	}
	
	sort(a+1,a+sum+1);
	
	if(a[sum]=='0'){
		cout<<"0";
		return 0;
	}else{
		for(ll i=sum;i>=1;i--)cout<<a[i];
	}
	
	return 0;
}
