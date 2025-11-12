#include<bits/stdc++.h>
using namespace std;
int a[10],b;
string o;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>o;
	for(int i=0;i<o.size();i++){
		if(o[i]>='0'&&o[i]<='9'){
			a[o[i]-'0']++;b++;
		}
	}
	if(a[0]==b){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--)cout<<i;
	}
	return 0;
} 