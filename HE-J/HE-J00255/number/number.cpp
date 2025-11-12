#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
bool cmp(int x,int y){
	return x>y;
}
int a[N],cnt=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n = s.length();
	if(n == 1) cout << s;
	for(int i=0;i<=n;i++){
		if(s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i];
			cnt++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
