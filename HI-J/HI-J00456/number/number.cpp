#include<bits/stdc++.h> 
using namespace std;
int a[1000010];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<1000010;i++){
		a[i]=-1;
	}
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
		}
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<s.size();i++){
		if(a[i]!=-1) cout<<a[i];
	}
	return 0;
}
