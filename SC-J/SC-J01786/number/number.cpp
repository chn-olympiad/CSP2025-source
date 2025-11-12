#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int x=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[x++]=s[i]-'0';
		}
	}
	sort(a+1,a+x,cmp);
	for(int i=1;i<x;i++){
		cout<<a[i];
	}
	return 0;
} 