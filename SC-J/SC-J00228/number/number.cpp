#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000005],n,x=1;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	x--;
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 