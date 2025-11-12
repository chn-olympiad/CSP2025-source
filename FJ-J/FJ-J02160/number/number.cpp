#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],ll;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ll]=s[i]-'0';
			ll++;
		}
	}
	sort(a,a+ll,cmp);
	for(int i=0;i<ll;i++){
		cout<<a[i];
	}
	return 0;
}
