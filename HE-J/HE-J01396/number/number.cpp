#include<bits/stdc++.h>
using namespace std;
int a[1000011],l=0;
bool com(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') {
			l++;
			a[l]=s[i]-'0';
		}
	}
	sort(a+1,a+1+l,com);
	for(int i=1;i<=l;i++){
		cout<<a[i];
	}
	return 0;
}
