#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r"stdin);
	freopen("number.out","r"stdout);
	string a;
	cin>>a;
	for(int i=0;i<=9;i++){
		if(a[i]<a[i+1]){
			cout<<a[i+1]<<a[i];
			break;
		}else cout<<a[i]<<a[i+1];
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
