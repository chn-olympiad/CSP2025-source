#include<bits/stdc++.h>
using namespace std;
string s;
int ans,a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ss=s.size();
	for(int i=0;i<ss;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	//sort(a+1,a+1+ans);
	for(int i=9;i>=1;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i; 
		}
	}
	return 0;
} 
