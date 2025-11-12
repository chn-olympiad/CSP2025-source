#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int t[10]={0};
	cin>>a;
	int s=a.size();
	for(int i=0;i<s;i++){
		if(a[i]>='0'&&a[i]<='9'){
			t[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(t[i]!=0){
			for(int j=1;j<=t[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
