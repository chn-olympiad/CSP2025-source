#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char a[1000006];
	cin>>s;
	int b=1;
	int n = s.length();
	for(int i=0;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[b] = s[i];
			b++;
		}
	}
	char d;
	for(int i=1;i<=b;i++){
		for(int j=2;j<=b;j++){
			if(a[j]<a[i]){
				d= a[i];
				a[i]=a[j];
				a[j] = d;
			}
		}
		
	}
	for(int i=1;i<=b;i++){
		cout<<a[i];
	}
} 
