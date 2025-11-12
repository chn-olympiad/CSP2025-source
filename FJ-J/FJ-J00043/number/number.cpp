#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1000100;
int a[N],t=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a+1,a+t+1);
	for(int i=t;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
