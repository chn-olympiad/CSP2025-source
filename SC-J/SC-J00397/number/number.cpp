#include<bits/stdc++.h>
using namespace std;

string str;
int a[10000005],i,s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	while(i<str.size()){
		if(str[i]>='0'&&str[i]<='9'){
			a[s]=str[i]-'0';
			s++;
		}
		i++;
	}
	sort(a,a+s);
	for(int j=s-1;j>=0;j--){
		cout<<a[j];
	}
	return 0;
} 