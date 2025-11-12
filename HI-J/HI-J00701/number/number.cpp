#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin); 
freopen("number.out","w",stdout);
char a[100000];
int b[100000];
cin>>a;
long long k=0;
for(int i=0;a[i]!=0;i++){
	if(a[i]>='0'&&a[i]<='9'){
		k++;
		b[k]=a[i]-'0';
	}
}
for(int i=1;i<=k-1;i++){
	for(int f=1;f<=k-1;f++){
		if(b[f]>b[f+1]){
			b[f]=b[f]+b[f+1];
			b[f+1]=b[f]-b[f+1];
			b[f]=b[f]-b[f+1];
		}
	}
}
long long h=0;
long long hh;
for(int i=1;i<=k;i++){
	hh=b[i];
	for(int f=1;f<=i-1;f++){
	hh*=10;	
	}
	h+=hh;
}
cout<<h;
return 0;
}
