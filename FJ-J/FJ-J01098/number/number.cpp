#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0; i<len; i++){
		if('0'<=s[i]&&s[i]<='9'){
			char c=s[i];
			int x=c-'0';
			a[++k]=x;
		}
	}
	sort(a+1,a+1+k);
	for(int i=k; i>=1; i--){
		cout<<a[i];
	}
	return 0;
} 
