#include<iostream>
#include<cstdio>
char s[100001], m[100001]; 
int a[11], c[11][1001];
using namespace std;
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b=0, d=0;
	cin >> s;
	m = s;
	else{
		for(int i=0; i<length(s); i++){
			if(s[i]>='0'&&s[i]<='9'){
				a[b]=s[i];
				b++;
			}
			else{
				d++; 
			}
		}
		if(d==0){
			cout << s;
		}
		for(int i=1; i<=b; i++){
			for(int j=1; j<=b; j++){
				if(a[i]<a[j]){
					int t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
	}
	return 0;
} 


