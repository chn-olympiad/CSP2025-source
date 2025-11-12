#include<bits/stdc++.h>
using namespace std;
int n,m,zs,xr;
int a[110],kc[11][11];
int zy=1,zx=1;//hang,lie
bool kg=1;//1:1,0=2
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	zs=n*m;
	for(int i=1;i<=zs;i++)
	cin>>a[i];
	xr=a[1];
	sort(a+1,a+zs+1,cmp);
	for(int i=1;i<=zs;i++){
		if(kg==1){
		if(zy<=n){
			kc[zx][zy]=a[i];
			if(a[i]==xr){
				cout<<zx<<" "<<zy<<endl;
				return 0;
			}
			zy+=1;
			if(!(zy<=n)){
				zy-=1;
			    zx+=1;
			    kg=0;
			}
		}
		
}else{
		if(zy>=1){
			kc[zx][zy]=a[i];
			if(a[i]==xr){
				cout<<zx<<" "<<zy<<endl;
				return 0;
			}
			zy-=1;
			if(!(zy>=1)){
				zy+=1;
			    zx+=1;
			    kg=1;
			}
		}
	}

}

	
	return 0;
}
