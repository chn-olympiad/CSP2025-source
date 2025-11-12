#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
int len,k=0;
int cm(int a,int b){
	return a>=b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	len=s.length();
	for(int i=0;i<len;++i){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-'0';
			++k;
		}
	}
	sort(a,a+k,cm);
	for(int j=0;j<k;++j){
		cout<<a[j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}