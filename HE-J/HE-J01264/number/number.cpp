#include<bits/stdc++.h>
using namespace std;
string s;
long long k=0,a[100010];
bool cmp(int a11,int b11){
	return a11>b11;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	return 0;
} 
