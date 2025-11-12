#include<bits/stdc++.h>
using namespace std;
int m[100005];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(0<=(a[i]-'0')&&(a[i]-'0')<=9){
			m[i]=a[i]-'0';
		}
		else{
			m[i]=-1;
		}
	}
	sort(m,m+n);
	for(int i=n;i>0;i--){
		if(m[i-1]==0&&i==n){
			cout<<0;
			return 0;
		}
		else if(m[i-1]!=-1){
			cout<<m[i-1];
		}
	}
	return 0;
}