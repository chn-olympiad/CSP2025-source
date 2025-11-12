#include<bits/stdc++.h>
using namespace std;
int a[1000010]={0},o=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
//	preopen("input.in","r",stdin);
//	preopen("output.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[o++]=s[i]-'0';
		}
	}
	sort(a,a+o);
	for(int i=o-1;i>=0;i--){
		cout<<a[i];
	}
	
	
	
	
	return 0;
}
