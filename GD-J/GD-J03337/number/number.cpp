#include<bits/stdc++.h>
using namespace std;
int cnt;
int a[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[cnt++] = s[i] - '0';
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout << a[i];
	}
	return 0;
} 
