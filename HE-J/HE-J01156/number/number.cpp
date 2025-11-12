#include<bits/stdc++.h>
using namespace std;
char a[10000000];
int x=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b=0;
	scanf("%s",&a);
	int n=strlen(a);
	int shu[n];
	for(int i=0;i<n;i++){
		shu[i]=0;
	}
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			b++;
		}
		if(a[i]>='0' && a[i]<='9'){
			shu[x]=int(a[i]-48);
			x++;
		}
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<x;j++){
			if(shu[i]>shu[j]){
				swap(shu[i],shu[j]);
		}}
	}
	for(int i=0;i<n;i++){
		if(shu[i]){
			cout<<shu[i];
		}}
	for(int i=0;i<b;i++){
		cout<<0;
	}
	return 0;
} 
