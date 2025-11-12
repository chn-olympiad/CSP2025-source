#include<bits/stdc++.h>
using namespace std;
int t,n,cnt=0,sum;
int a[31][3];
int s[6];
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
cin>>t;
for(int f=0;f<t;f++){

	cin>>n;
	for(int i=0;i<n;i++){
	 for(int j=0;j<3;j++){
	cin>>a[i][j];
  }
}
    s[0]=a[0][0]+a[1][1];
    s[1]=a[0][0]+a[1][2];
    s[2]=a[0][1]+a[1][0];
    s[3]=a[0][1]+a[1][2];
    s[4]=a[0][2]+a[1][0];
    s[5]=a[0][2]+a[1][1];
    
    sort(s,s+6,greater<int>());
    cout<<s[0]<<"\n";
    
}
	return 0;
}
