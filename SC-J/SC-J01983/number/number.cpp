#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],gsa=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			gsa++;
			a[gsa]=s[i]-'0';
		}
	}sort(a+1,a+gsa+1,cmp);
	for(int i=1;i<=gsa;i++){
		cout<<a[i];
	}
	return 0;
}