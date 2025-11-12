#include <bits/stdc++.h>
using namespace std;
int n,a[5005],cnt;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cnt += a[i];
	}
	sort(a + 1,a + 1 + n,cmp);
	if(cnt > 2 * a[1]){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}
