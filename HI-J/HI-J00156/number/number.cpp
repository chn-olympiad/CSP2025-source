#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a1;
	cin>>a1;
	int n;
	n=a1.size();
	string a2[n]=" ";
	for(int i=0;i<n;i++){
		if(a1[i]>='0'&&a1[i]<='9'){
			a2[i]=a1[i];
		}
	}
	sort(a2,a2+n);
	for(int i=n-1;i>=0;i--){
		if(a2[i]!=" "){
			cout<<a2[i];
		}
	}
	return 0;
}
