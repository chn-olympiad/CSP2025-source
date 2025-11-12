#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int b[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int l=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			l++;
			b[l]=s[i]-'0';
		}
	}
	sort(b+1,b+l+1,cmp);
	for(int i=1;i<=l;i++){
		cout<<b[i];
	}
	
	return 0;
} 
