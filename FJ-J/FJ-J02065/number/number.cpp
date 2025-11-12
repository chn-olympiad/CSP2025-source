#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n[11]={0},j=0;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
			n[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int b=1;b<=n[i];b++){
		    cout<<i;
	    }
	}
	return 0;
}
