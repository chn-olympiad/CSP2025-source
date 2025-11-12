#include<bits/stdc++.h>
using namespace std;
string a,b;
int i,l,l1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	l=a.size();
	for(i=0;i<l;i++){
		if(a[i]>='0' && a[i]<='9'){
		b=b+a[i];
		}
	}
	sort(b.begin(),b.end());
	for(i=b.size()-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
