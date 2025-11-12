#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto c:s){
		if(c>='0' && c<='9'){
			a[++cnt]=c-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}

