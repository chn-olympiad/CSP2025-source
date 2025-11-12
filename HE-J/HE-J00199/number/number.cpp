#include<bits/stdc++.h>
using namespace std;
string s;
long long int a[1000006],j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a-1,a+j);
	j--;
	for(;j>=0;j--){
		cout<<a[j];
	}
	return 0;
}
