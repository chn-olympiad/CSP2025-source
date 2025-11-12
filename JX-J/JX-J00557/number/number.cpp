#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],x,z=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	x=s.size();
	for(int i=0;i<x;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			z++;
			a[z]=s[i]-'0';
			//cout<<a[z];
			//cout<<z;
		}
	}
	sort(a+1,a+1+z);
	for(int i=z;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
