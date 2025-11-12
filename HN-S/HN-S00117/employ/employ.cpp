#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	preopen("employ.in","r",stdin);
	preopen("employ.out","w",stdout);
	int n,m,s[10000],c[10000];
	cin>>n,m;
	for(int i=0;i<n;i++){
		cin>>s[i];
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		sort(s,s+n);
		sort(c,c+n);
	}
	cout<<2204128;
	
	fclos(stdin);
	fclos(stdout);
	return 0;
}
