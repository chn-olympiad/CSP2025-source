#include<bits/stdc++.h>
using namespace std;
string a;
int b,c[10]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out ","w",stdout);
	cin>>a;
	b=a.length();
	for(int i=0;i<b;i++)
		if(!(a[i]>='a'&&a[i]<='z'))c[a[i]-'0']++;
	for(int i=9;i>=0;i--){
		while(c[i]){
			cout<<i;
			c[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
