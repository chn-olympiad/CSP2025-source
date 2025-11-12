#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n[(a.size()+5)];
	int p=-1;
	for(int i=0;i<=a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
				p++;
			n[p]=(a[i]-48);
		
		}
	}
	sort(n,n+p+1,cmp);
	for(int i=0;i<=p;i++){
		cout<<n[i];
	}
	return 0;
}