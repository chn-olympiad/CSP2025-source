#include<bits/stdc++.h>
using namespace std;
string a;
int b[100005];
int l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;

	int n=a.size();
	for(int i=0;i<n;i++){
		int m=a[i];
		if(m-'0'<=9 and m-'0'>=0){
			b[i]=m-'0';
		}else if(m-'0'>9){
			l++;
		}
	}
	sort(b,b+n);
	for(int i=n-1;i>=l;i--){
		cout<<b[i];
	}
	return 0;
}		   
