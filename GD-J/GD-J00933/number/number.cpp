#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int a[N];
long long idx=0;
bool cmp(int b,int c){
	return b>c;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++idx]=s[i]-'0';
		}
	}
	sort(a+1,a+1+idx,cmp);
	for(int i=1;i<=idx;i++){
		cout<<a[i];
	}
	return 0;
} 
