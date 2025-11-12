#include<bits/stdc++.h>
using namespace std;
string s;
int top;
int a[1000005];
bool cmp(int b,int c){
	return b>c;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			top++;
			a[top]=s[i]-'0';
		}
	}
	sort(a+1,a+top+1,cmp);
	for(int i=1;i<=top;i++){
		cout<<a[i];
	}
	return 0; 
} 
