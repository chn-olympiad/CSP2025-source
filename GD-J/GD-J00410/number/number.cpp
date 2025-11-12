#include<bits/stdc++.h>
using namespace std;
string n;
int a[1000005],z=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0' && n[i]<='9'){
			z++;
			a[z]=int(n[i]-'0');
		}
	}
	sort(a,a+z+1);
	for(int i=z;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
