#include <bits/stdc++.h>
using namespace std;
int num[1000005],n=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[n] = s[i]-48;
			n++;
		}
	}
	sort(num+1,num+1+n,cmp);
	for(int i=1;i<n;i++){
		cout << num[i];
	}
	return 0;
} 
