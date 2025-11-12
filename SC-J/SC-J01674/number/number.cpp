#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;
int a[1000005],x;

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=s.size();
	for(int i=0;i<k;i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
			a[x]=s[i]-'0';
		}
	}
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		printf("%lld",a[i]);
	}
	return 0;
}