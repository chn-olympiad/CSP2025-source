#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],r;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if((s[i]-'0')<=9&&(s[i]-'0')>=0){
			a[++r]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+r,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=r;i++){
		cout<<a[i];
	}
	return 0;
}
