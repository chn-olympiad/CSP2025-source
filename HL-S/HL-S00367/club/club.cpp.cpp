#include<bits/stdc++.h>
using namespace std;
long long t,n[6],a[6][100001][3];
long long fhz(long long d,long long b,long long c){
	if(d>=b&&d>=c){
		return d;
	}
	else if(b>=d&&b>=c){
		return b;
	}
	else if(c>=d&&c>=b){
		return c;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n[i];
		for(int j=0;j<n[i];j++){
			for(int l=0;l<3;l++){
				cin>>a[i][j][l];
			}
		}
	}
	for(int i=0;i<t;i++){
		long long s=0;
		for(int j=0;j<n[i];j++){
			if(fhz(a[i][j][1],a[i][j][2],a[i][j][0])==a[i][j][0]){
				s+=a[i][j][0];
			}
			else if(fhz(a[i][j][1],a[i][j][2],a[i][j][0])==a[i][j][2]){
				s+=a[i][j][2];
			}
			else if(fhz(a[i][j][1],a[i][j][2],a[i][j][0])==a[i][j][1]){
				s+=a[i][j][1];
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
