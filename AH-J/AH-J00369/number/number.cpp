#include<bits/stdc++.h>
using namespace std;
string a;
long long b[30],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	long long la =a.size();
	for(int i=0;i<la;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int k=0;k<b[i];k++){
			cout<<i;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
