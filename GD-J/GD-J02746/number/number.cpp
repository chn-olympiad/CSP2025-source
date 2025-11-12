#include<bits/stdc++.h>
using namespace std;
bool p(int a,int b){
	return a>b;
}
int a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	int j=0;
	cin>>s;
	for(char i:s){
		if (i>='0' && i<='9')
			a[j++]=i-'0';
	}
	sort(a,a+j,p);
	
	for(int i=0;i<j;i++) cout<<a[i];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
