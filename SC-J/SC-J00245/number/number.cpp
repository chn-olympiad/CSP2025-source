#include<bits/stdc++.h>
using namespace std;
string s;
int j;
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i];
			j++;
		}
	}
	sort(a,a+j,greater<char>());
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
} 