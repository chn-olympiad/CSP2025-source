#include<bits/stdc++.h>
using namespace std;
int b[101];
int main(){
	freopen("number.in", "r",stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin>>a;
	for(unsigned int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]--){
			cout<<i;
		}
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
