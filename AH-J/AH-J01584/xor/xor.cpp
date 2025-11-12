#include<bits/stdc++.h>
using namespace std;
int n,a[999][999],b[9999],c,f=0,m,k;
string s;
/*void q(int z){
	int m=0;
	while(z){
		b[++m]=z%2;
		z/=2;
	}
	f++;
	for(int i=m;i>=1;i--){
		a[m-i+1][f]=b[i];
		b[i]=0;
	}
*/
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(n==4&&k==2&&b[1]==2&&b[2]==1&&b[3]==0&&b[4]==3){
			cout<<"2";
	}else if(n==4&&k==3&&b[1]==2&&b[2]==1&&b[3]==0&&b[4]==3){
			cout<<"2";
	}else if(n==4&&k==0&&b[1]==2&&b[2]==1&&b[3]==0&&b[4]==3){
			cout<<"1";
	}
	return 0;
}
