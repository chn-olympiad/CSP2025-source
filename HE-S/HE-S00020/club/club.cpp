#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
  int x;
	cin>>x;
	
	for(int j=1;j<=x;j++){
		int a1,a2,a3,b1=0,b2=0,b3=0,ans=0;
	cin>>a1>>a2>>a3;
	if(a1>a2&&a1>a3){
		b1++;ans+=a1;
	}else if(a2>a1&&a2>a3){
		b2++;ans+=a2;
	}else if(a3>a2&&a3>a1){
	b3++;ans+=a3;}
	
}if(b1<=x/2&&b2<=x/2&&b3<=x/2){
		cout<<ans<<endl;
}
}}
