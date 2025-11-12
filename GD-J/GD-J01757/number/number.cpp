#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string a;
int b[1000001],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>a;
	
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
			b[n]=a[i]-'0';
			n++;			
		}
	} 
	sort(b,b+n);
	for(int i=n-1;i>=0;i--)cout<<b[i];
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
