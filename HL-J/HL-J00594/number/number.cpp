#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
char a1[1000005];
int a[1000005];
void bubble(int n){
	for(int i=n; i>1; i--){
		for(int j=1; j<i; j++){
			if(a[j]<a[j+1]) swap(a[j],a[j+1]);
		}
	}
}
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a1;
	int len=strlen(a1),b=0;
	for(int i=0; i<len; i++){
		if(a1[i]-'0'>=0 && a1[i]-'0'<=9){
			b++;
			a[b]=a1[i]-'0';
		}
	}
	bubble(b);
	for(int i=1; i<=b; i++){
		cout<<a[i];
	}
	return 0;
} 
