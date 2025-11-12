#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
string s;
int a[1000005],gs;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.length()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			gs++;
			a[gs]=s[i]-'0';
		}
	}
	sort(a+1,a+gs+1);
	for(int i=gs;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}