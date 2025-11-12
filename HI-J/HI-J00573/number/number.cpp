#include<bits/stdc++.h>
using namespace std;
char a[1000000];
char c[1000000];
int main(){
	string p;
	int ck=0;
	cin>>p;
	for(int i=0;i<1000;i++){
		if('0'<=p[i] & p[i]<='9'){
			c[i]=int(p[i]);
		}
	}
	sort(c+0,c+1000);
	for(int i=0;i<1000;i++){
		if(c[i]==2 and ck==0){
			ck+=1;
			continue;
		}
		cout<<c[i];
		
	}
	return 0;
} 
