#include<bits/stdc++.h>
using namespace std;
string a;
int b[12]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9') b[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<b[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
 
