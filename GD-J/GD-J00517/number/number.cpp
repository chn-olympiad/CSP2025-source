#include<bits/stdc++.h>
using namespace std;
int a[100];
string k;
long long n=0;
long long len1=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>k;
	len1=k.length();
	for(int i=0;i<len1;i++){
		if(k[i]>='0'&&k[i]<='9'){
			n++;
			a[k[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
} 
