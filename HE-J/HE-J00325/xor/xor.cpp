#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=2e6+10;
int m,n,r,cnt=0;
bool p1,p2,p3,p4,p5,p6;
int a[N],b[N],f[M][3];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			p1=1;
		}
		if(a[i]!=1){
			p2=1;
		}
	}
	if(m==0&&p1==0){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]^b[i-1];
	}
	int o=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(i==j){
				o=a[i];
			}
			else{
				o=b[j]^b[i];	
			}
			if(o==m){
				cnt++;
			}		
		}
	}
	cout<<cnt;
	return 0;
}
