//GZ-S00099 贵阳市第一中学 周代岳
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	char a[n];
	int t[n];
	int ne[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
		t[i] = int(a[i]);
	}
	for(int i=0;i<n;i++){
		cin >> ne[i];
	}
	int ans=1;
	for(int i=n;i>=1;i--){
		ans *= i;
	}
	cout << ans;
	return 0;
	
}
