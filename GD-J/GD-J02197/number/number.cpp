#include<bits/stdc++.h>
using namespace std;
int a[1000010],z=1;
char b[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	int c=strlen(b);
	for(int i=0;i<c;i++){
		if(0<=b[i]-'0'&&b[i]-'0'<=9){
			a[z]=b[i]-'0';
			z++;
		}
	}  
	sort(a+1,a+z);
	for(int i=z-1;i>=1;i--){
		cout<<a[i];
	}	 
	return 0; 
} 
