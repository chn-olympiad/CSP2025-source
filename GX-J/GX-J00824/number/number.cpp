#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
string s;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x=0;
	for(long unsigned int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++x]=s[i]-'0';
		}
	}
	sort(a+1,a+1+x,cmp);;
	for(int i=1;i<=x;i++){
		cout<<a[i];
	}
	return 0;
}
