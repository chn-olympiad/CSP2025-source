#include<bits/stdc++.h>
using namespace std;
int f[10001];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9') f[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(f[i]){
			printf("%d",i);
			f[i]--;
		}
	}
	return 0;
} 
