#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000100],n;
bool ss(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n++]=s[i]-'0';
		}
	}
	sort(a,a+n,ss);
	for(int i=0;i<n;i++){
		cout << a[i];
	}
	
	return 0;
} 