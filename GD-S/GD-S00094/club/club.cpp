#include<bits/stdc++.h>
using namespace std;
int a[110000],ans;
int main(){
int t,w1,w2,w3,n;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
for(int i=1;i<=t;i++){
cin>>n;
for(int j=1;j<=n;j++){		
cin>>w1>>w2>>w3;
a[j]=w1;
}	
sort(a,a+n+1);
for(i=n;i>=n/2;i--){
ans+=a[i];
cout<<ans;
}	

}
		
}
