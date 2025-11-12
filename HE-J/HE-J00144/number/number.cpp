#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int b[100010],l; 
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[l]=s[i]-'0';
			l++;
		}
	}
	sort(b+1,b+l+1,cmp);
	cout<<s[l];	
	return 0;
}
