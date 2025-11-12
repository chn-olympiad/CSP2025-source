#include <bits/stdc++.h>
using namespace std;
int n[1000005];
string s;
bool px(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int b = 0;
	int a= s.length();
	for(int i = 0;i<a;i++){
		if(s[i] - '0'<=9 && s[i] - '0'>=0){
			int k = s[i] - '0';
			n[b] = k;
			b++;
		}
	}
	sort(n,n+a,px);
	for(int i = 0;i<b;i++){
		cout<<n[i];
	}
	return 0;
}
