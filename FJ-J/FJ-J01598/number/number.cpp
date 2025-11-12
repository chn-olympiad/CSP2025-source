#include<bits/stdc++.h>
using namespace std;
string s;
int a[9001000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int q=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			q++;
			a[q]=s[i]-'0';
		}
	}
	sort(a+1,a+1+q,cmp);
	for(int i=1;i<=q;i++){
		cout<<a[i];
	}
	return 0;
}
