#include<bits/stdc++.h>
using namespace std;

string s;
int a[10000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int i=0,j=0;
	for(;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(int x=j;x>=0;x--){
		if(x==j&&a[x]==0){
			continue;
		}
		cout<<a[x];
	}
	return 0;
}
