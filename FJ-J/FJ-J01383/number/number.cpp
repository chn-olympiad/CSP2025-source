#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int num,a[N],cnt=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	num=s.length();
	for(int i=0;i<num;i++){
		if('0'<=s[i] && s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>1;i--){
		cout << a[i];
	}
	return 0;
} 
