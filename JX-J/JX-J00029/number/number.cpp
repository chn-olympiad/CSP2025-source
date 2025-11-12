#include<bits/stdc++.h>
using namespace std;
int tong[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int ln=n.size();
	for(int i=0;i<ln;i++){
		if(n[i]<='9'&&n[i]>='0') tong[n[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(tong[i]--) printf("%d",i);
	}
	return 0;
}
