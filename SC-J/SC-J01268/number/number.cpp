#include<bits/stdc++.h>
using namespace std;
int a[1000005],k=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++) cout<<a[i];
	return 0;
}