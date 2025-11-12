#include<bits/stdc++.h>
using namespace std;
string x;
char s[1000001];
long long n[1000001]={0};
long long a;
int n1=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=strlen(s);
	for(int i=0;i<=a;i++){
		if(s[i]>='0' and s[i]<='9'){
			n[n1]=s[i]-'0';
			n1++;
		}
	}
	for(int i=0;i<=a;i++){
		for(int j=a;j>=i;j--){
			if(n[i]<n[j]){
				swap(n[i],n[j]);
			}
		}
	}
	for(int i=0;i<n1;i++){
		cout<<n[i];
	}
	return 0;
}
