#include<bits/stdc++.h>
using namespace std;
string n,a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9')a[n[i]-'0']+=n[i];
	}
	string s="";
	for(int i=9;i>=0;i--){
		s+=a[i];
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
