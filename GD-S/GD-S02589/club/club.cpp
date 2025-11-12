#include<bits/stdc++.h>
using namespace std;
long long n,a[110000],b[110000],c[110000],ca,t;
int abc(int a1,int b1,int c1){
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			ca+=max(a[i],max(b[i],c[i]));
		}
		cout<<ca;
	}
	return 0;
}
