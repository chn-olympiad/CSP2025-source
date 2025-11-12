#include<bits/stdc++.h>
using namespace std;
string n;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[n[i]-'0']++;
		}
	}
	int flag=1;
	for(int i=9;i>=1;i--){
		while(a[i]){
			flag=0;
			a[i]--;
			cout<<i;
		}
	}
	if(flag){
		cout<<"0";
	}else{
		while(a[0]){
			a[0]--;
			cout<<"0";
		}
	}
	return 0;
} 
