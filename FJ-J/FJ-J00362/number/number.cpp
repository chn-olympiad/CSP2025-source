#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	string s;
	int a[100],z=0,x=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[z]=s[i]-'0';
			for(int j=0;j<z;j++){
				if(a[z]>a[j]){
					swap(a[z],a[j]);
				}
			}
			z++;
			}}
		for(int i=0;i<z;i++){
			x=a[i]+x*10;
			}
		cout<<x;
		fclose(stdin);
		fclose(stdout);
	return 0;
}
