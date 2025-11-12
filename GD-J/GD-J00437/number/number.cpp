#include <bits/stdc++.h>
using namespace std;
int cnt,num[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0' && s[i]<='9'){
			num[++cnt]=(s[i]-'0');
		}
	}
	sort(num+1,num+cnt+1,cmp);
	if (num[1]==0){
		cout << num[1];
		return 0;
	}
	for (int i=1;i<=cnt;i++){
		cout << num[i];
	} 
	return 0;
}
