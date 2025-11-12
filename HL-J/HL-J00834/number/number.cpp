#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n = s.size();
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[i] = s[i]-'0';
		}else{
			cnt++;
		}	
	}
	sort(a,a+n,cmp);
	for(int i=0;i<s.size()-cnt;i++){
		cout << a[i];
	}
	return 0;
}
