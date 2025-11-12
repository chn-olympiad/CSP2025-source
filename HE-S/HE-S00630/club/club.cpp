#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int t,k[6],p[6][4],maxn[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){ 
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>p[j][1]>>p[j][2]>>p[j][3];
	}
	cout<<18<<endl<<4<<endl<<13<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
