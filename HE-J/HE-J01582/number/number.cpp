#include<bits/stdc++.h>
using namespace std;
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>n;

	int a[n.size()+3]={},o=1,b[n.size()+3]={};
	for(int i=0;i<n.size();i++){

		a[i]=n[i]-'0';

	}
	for(int i=0;i<n.size();i++){
		if(a[i]>=0&&a[i]<=9){
			b[o]=a[i];
			o++;

		}


	}
	sort(b+1,b+o+1);

	for(int i=o;i>=2;i--){
		cout<<b[i];
	}
	return 0;
}


