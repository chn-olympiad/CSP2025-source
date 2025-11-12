#include<bits/stdc++.h>
using namespace std;
string a;
const long long q=1e7+5;
long long n[q];
long long n_n=0;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			n[n_n]=a[i]-48;
			n_n++;
			//cout<<a[i]<<" "<<n[n_n-1]<<endl;
		}
	}
	sort(n,n+n_n,cmp);
	for(int i=0;i<n_n;i++){
		cout<<n[i];
	}
	
	
	return 0;
}
