#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ans = 0;
	string s;
	int tot = 0;
	cin>>s;
	for(int i = 0;i < s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			tot++;
			a[tot] = s[i]-'0';
		}
	}
	sort(a+1,a+tot+1);
	for(int i = tot;i > 0;i--){
		int k = 1;
		for(int j = 1;j < i;j++){
			k*=10;
			
		}
		a[i]*=k;
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
