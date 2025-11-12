#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--) printf("%d",i);
	}
}
