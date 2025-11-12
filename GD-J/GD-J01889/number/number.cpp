#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],q;
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	s=" "+s;
	for(int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++q]=s[i]-'0';
		}
	}
	sort(a+1,a+q+1,cmp);
	for(int i=1;i<=q;i++){
		cout<<a[i];
	}
	return 0;
}
