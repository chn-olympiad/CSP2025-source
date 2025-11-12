//number
#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	int num=0;
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if (s[i]>='0' && s[i]<='9'){
			num++;
			a[num]=s[i]-'0';
		}
	}
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
