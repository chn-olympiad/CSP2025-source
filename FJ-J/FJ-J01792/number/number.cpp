#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
char a[N];
bool cmp(char a,char b){
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int q=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++q]=s[i];
		}
	}
	sort(a+1,a+q+1,cmp);
	for(int i=1;i<=q;i++){
		cout<<a[i];
	}
	return 0;
}
