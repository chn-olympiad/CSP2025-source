#include<bits/stdc++.h>
using namespace std;
struct pp{
	int z;
	int cj;
}a[105];
int n,m,sum;
bool cmp(pp wsx,pp edc){
	return wsx.cj>edc.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;
		a[i].z=i; 
	}
	sort(a+1,a+(n*m)+1,cmp);
	/*
	for(int i=1;i<=n*m;i++){
		cout<<a[i].cj<<' '<<a[i].z<<"\n";
	}
	*/
	bool bj=true;
	for(int i=1;i<=m;i++){
		if(bj=true){
			for(int j=1;j<=n;j++){
				sum++;
				if(a[sum].z==1){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}	
			}
			bj=false;
		}else{
			for(int j=n;j>0;j--){
				sum++;
				if(a[sum].z==1){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}	
			}
			bj=true;
		}
	}
	cout<<a[1].cj;
	return 0;
}

