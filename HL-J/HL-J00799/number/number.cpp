#include<bits/stdc++.h>
using namespace std;
const int maxn= 1e7;
int a[maxn];
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt = 1;
	for(int i = 0; i < s.length(); i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[cnt] = s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt,cmp);
	for(int i=1; i<cnt; i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
