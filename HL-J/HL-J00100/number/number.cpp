#include <bits/stdc++.h>
using namespace std;
int a[100010];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	long long pos=0,n=0;
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			 a[pos++]=s[i]-'0';
			n++;
		}
		
	}
	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++){
		cout<<a[i];
	}

	return 0;
}