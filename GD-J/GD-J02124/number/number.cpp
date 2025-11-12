#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N];
int n=1;
char b[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>b[n]){
		break;
	}
	while(b>0){
		a[n]=b%10;
		b/=10;
		n++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
} 
