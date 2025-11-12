#include<bits/stdc++.h>
using namespace std;
string s;
int o;
bool cmp(int x,int y){
	return x>y;
}
int a[10000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[i]=s[i]-'0';
			o++;
		}
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<o;i++){
		cout<<a[i];
	}
	return 0;
} 
