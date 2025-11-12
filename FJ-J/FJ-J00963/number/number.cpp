#include<bits/stdc++.h>
using namespace std;
string a,b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b+=a[i];
		}
	}
	sort(b.begin(),b.end());
	for(int i=b.size()-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
