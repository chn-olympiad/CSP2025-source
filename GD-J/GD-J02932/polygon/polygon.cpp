#include <bits/stdc++.h>
using namespace std;
int a[5010];
int n;
void s1(){
	int t=0,m=0;
	for(int i=1;i<=n;i++){
		t+=a[i];
		m=max(m,a[i]);
	}
	if(t>m*2) cout<<1;
	else cout<<0;
}
void s2(){
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3) s1();
	else cout<<0;
	return 0;
} 
