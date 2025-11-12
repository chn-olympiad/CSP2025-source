#include <bits/stdc++.h>
using namespace std;
string a;
int ans[100005],kl;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.length();
	for(int i=0;i<len;i++){
		if('0'<=a[i] && a[i]<='9'){
			kl++;
			ans[kl]=int(a[i])-48;
		}
	}
	sort(ans+1,ans+kl+1);
	for(int i=kl;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
}
