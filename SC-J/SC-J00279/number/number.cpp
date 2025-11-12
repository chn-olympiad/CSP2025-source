#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int a[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}for(int i=9;i>=0;){
		if(a[i]==0){
			i--;
			continue;
		}cout<<i;
		a[i]--;
	}
	return 0;
}