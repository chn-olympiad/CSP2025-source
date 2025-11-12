#include<iostream>
#include<algorithm>
using namespace std;
#define long long ll
string str;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
void f(string s){
	int ip=1;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[ip++]=s[i]-'0';
		}
	}
	sort(a+1,a+ip+1,cmp);
	for(int i=1;i<ip;i++){
		cout<<a[i];
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	f(str);
	return 0;
}