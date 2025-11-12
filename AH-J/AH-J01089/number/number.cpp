#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000000];
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=1+s[i]-'0';
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		if(a[i]!=0)cout<<a[i]-1;
	}
	return 0;
}
