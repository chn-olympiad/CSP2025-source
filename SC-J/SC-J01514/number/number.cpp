#include<bits/stdc++.h>
using namespace std;
int a[1000004];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;	
		}
	}
	sort(a+1,a+j);
	for(int c=j-1;c>=1;c--){
		cout<<a[c];
	}
	return 0;
}