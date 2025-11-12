#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
int n[t];
int a[t];
int b[t];
for(int i=0;i<t;i++){
		cin>>n[i]>>a[i]>>b[i];
		if(n[1]>n[2]>n[3]&&a[2]>a[1]>a[3]&&b[3]>b[2]>b[1]){
			cout<<n[1]+a[2]+b[3];
		}
	}
return 0;
}
