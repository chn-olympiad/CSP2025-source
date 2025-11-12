#include<bits/stdc++.h>
using namespace std;
string n;
int a[1000001],z;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			z++;
			a[z]=n[i]-48;
		}
	}
	sort(a+1,a+z,cmp);
	for(int i=1;i<=z;i++){
		cout<<a[i];
	}
	return 0;
}
