#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int y=0;
	int p=s.length();
	for(int i=0;i<p;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[y+1]=s[i]-'0';
			y++;
		}
	}
	sort(a+1,a+y+1);
	for(int i=y;i>=1;i--){
		cout<<a[i];
	}
}
