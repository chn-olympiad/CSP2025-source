#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a[1000005];
	int num=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i];
			num++;
		}
	}
	sort(a,a+num);
	for(int i=num-1;i>=0;i--){
		cout<<a[i];
	}return 0;
}