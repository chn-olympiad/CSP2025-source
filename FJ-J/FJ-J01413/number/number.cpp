#include<bits/stdc++.h>
using namespace std;
int n[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int s=a.size();
	for(int i=0;i<s;i++){
		if(a[i]<='9'&&a[i]>='0'){
			n[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(n[i]>0){
			n[i]--;
			cout<<i;
		}
	}
	return 0;
}
