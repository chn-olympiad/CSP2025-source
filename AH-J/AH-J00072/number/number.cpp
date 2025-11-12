#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
int idx=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<=l;i++){
		if(s[i]>='0' && s[i]<='9'){
			int t=s[i]-'0';
			a[idx++]=t;
		}	
	}
	sort(a+1,a+idx+1,cmp);
	for(int i=1;i<idx;i++) cout<<a[i]; 
	return 0;
}
