//wonder:100pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
void work(){
	string s;
	cin >> s;
	int tot = 0,len = s.size();
	for(int i = 0;i < len;i++){
		if(s[i] >= '0' && s[i] <= '9') a[++tot] = s[i] - '0';
	}
	sort(a+1,a+1+tot);
	for(int i = tot;i >= 1;i--) cout << a[i];
	return;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	int t = 1;
//	cin >> t;
	while(t--){
		work();
		if(t) cout << endl; 
	}
}
