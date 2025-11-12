#include<bits/stdc++.h>
using namespace std;
int a[1000005];
char b[1000005];
int k=1000000;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<k;i++){
		cin>>b[i];
	}
	int r=0;
	for(int i=0;i<k;i++){
		if(int(b[i])<58 and int(b[i]>46)){
			a[r]=int(b[i])-48;
			r++;
		}
	}
	for(int i=0;i<r;i++){
		int t=0,aa=i;
		for(int j=i-1;j>=0;j--){
			int ab=j;
			if(a[aa]>a[ab]){
				t=a[aa];
				a[aa]=a[ab];
				a[ab]=t;
				aa--;
			}
		}
	}
	for(int i=0;i<r;i++){
		cout<<a[i];
	}
	return 0;
}
