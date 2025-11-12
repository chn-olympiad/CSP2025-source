#include<bits/stdc++.h>
using namespace std;
int a[10];
string b,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	for(int i=0;i<b.size();i++){
		if(b[i]>='0'&&b[i]<='9')a[b[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		char d=i+'0';
		while(a[i]--)c+=d;
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

