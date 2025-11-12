#include<iostream>
using namespace std;
int n[10]={0};
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'<10&&a[i]-'0'>=0)n[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<n[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
