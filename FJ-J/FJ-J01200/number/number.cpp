#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int l=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[l]=s[i]-'0';
			++l;
		}
	}
	sort(a,a+l,cmp);
	for(int i=0;i<l;i++){
		cout<<a[i];
	}
	return 0;
}
