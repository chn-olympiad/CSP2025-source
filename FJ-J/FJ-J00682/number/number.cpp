#include<bits/stdc++.h>
using namespace std;
string s1;
long long a[10000005]={0},j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	getline(cin,s1);
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			j++;
			a[j]=s1[i]-'0';
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
