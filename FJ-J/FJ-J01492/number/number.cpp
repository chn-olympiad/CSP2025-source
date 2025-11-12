#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000006],len=0;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		int c=s[i];
		if('0'<=c&&'9'>=c){
			a[++len]=c-'0';
		}
	}
	sort(a+1,a+len+1);
	for(int i=len;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
