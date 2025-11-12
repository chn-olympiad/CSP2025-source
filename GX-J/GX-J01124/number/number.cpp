#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
bool cmp(int a,int b){
	return a > b;
}
int a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	int len = s.size();
	int j = 1;
	for(int i = 0; i < len; i++){
		if(s[i] >= '0' && s[i] <= '9') {
			a[j] = s[i] - '0';
			j++;
		}
	}
	int n = j;
	sort(a + 1,a + n,cmp);
	for(int i = 1; i < n; i++) printf("%d",a[i]);
	return 0;
}
