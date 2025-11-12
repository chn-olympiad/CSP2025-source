//GZ-S00225 观山湖区第九中学 李德睿
#include<bits/stdc++.h>
using namespace std;
int const N=1e5;
int t,n[N],m1[N],m2[N],m3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
	cin>>n[q];
	for(int i=1;i<=n[q];i++){
		cin>>m1[i]>>m2[i]>>m3[i];
	}
}
	for(int i=1;i<=t;i++)cout<<m1[i]+m2[i]+m3[i]<<endl;
	return 0;
} 
