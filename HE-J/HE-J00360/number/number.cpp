#include<bits/stdc++.h>
using namespace std;
string str;
int a[100010];
bool cmp(int l,int r){
	if(l>r) return true;
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int res;
	for(int i=0;i<str.length();i++){
		if(isdigit(str[i])){
			a[res++]=str[i]-'0';
		}
	}
	cout<<res<<" ";
	sort(a,a+res+1,cmp);
	for(int i=0;i<res;i++){
		cout<<a[i];
	}
	return 0;
}
