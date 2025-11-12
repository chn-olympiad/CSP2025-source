#include<bits/stdc++.h>
using namespace std;

int a[11][11],b[1001];

bool cmp(int a,int b){
	return a>b;
	}

int main(){
	int n,m,sh,xr;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	xr=b[1];
	cout<<xr<<endl;
	sort(b+1,b+n*m+1,cmp);
	
	/*for(int i=1;i<=n*m;i++){
		cout<<b[i];
	}*/
	sh=1;
	int i=1,j=1;
		while(sh<=n*m){
		a[i][j]=b[sh];
		if(b[sh]==xr){
			cout<<j<<" "<<i;
			return 0;
		}
		if(i==n){
			j++;
			for(int k=1;k<=n;k++){
				//i--;
				a[i][j]=b[sh];
				sh++;
					if(b[sh]==xr){
						cout<<j<<" "<<i;
						return 0;
					}
					if(i==1){j++;break;}
					i--;
				}
		}
		else{i++;}
		sh++;
		
	}
	return 0;

}
