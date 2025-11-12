#include <iostream>
#include <algorithm>
using namespace std;
const int N=1000000+10;
int a[N];
long long index=0;

string s;
bool cmp(int a,int b){
	return b<a;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]<='9'&&'0'<=s[i]){
			a[++index]=s[i]-'0';
		}
	}
	sort(a+1,a+1+index,cmp);
	bool boolean=false;
	for(long long i=1;i<=index;i++){
		if(boolean&&a[i]==0){
			cout<<a[i];
		}else if(a[i]!=0){
			cout<<a[i];
			boolean=true;
		}
		
	}
	if(boolean==false){
		cout<<0;
	}
	return 0;
}