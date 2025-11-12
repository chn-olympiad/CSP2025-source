#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s; 
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int shu=s[i]-'0';
			a[shu]++;
		}
	}
	for(int i=l;i>=0;i--){
		if(a[i]){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
