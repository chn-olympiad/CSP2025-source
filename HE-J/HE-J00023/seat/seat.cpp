#include<bits/stdc++.h>
using namespace std;
int  a[110],b[13][13];
int n,m,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1],f;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R) {
			f=i;
			break;
		}
	}
	int zong=n*m,fz=1;
	
	for(int i=1;i<=m;i++){
		if(fz==1){	
			for(int j=1;j<=n;j++){
				b[j][i]=a[zong];
				if(a[zong]==R){
					cout<<i<<' '<<j;
					return 0;
				}
				zong--;
			}
		}
		else if(fz==0){	
			for(int j=n;j>=1;j--){
				b[j][i]=a[zong];
				if(a[zong]==R){
					cout<<i<<' '<<j;
					return 0;
				}
				zong--;
			}
		}
		if(fz==0)fz=1;
		else fz=0;
		
	}
	return 0;
}
