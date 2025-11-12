#include<bits/stdc++.h>
using namespace std; 
int a[100010];
int cnt=0;
int main(){
	freopen("number.in.txt","r",stdin);
	freopen("number.out.txt","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt++]=s[i]-'0';
		}
	}
	
	sort(a,a+cnt);
	
	for(int i=cnt-1;i>=0;i--){
		cout<<a[i]<<'\n';
	}
	return 0;
}
