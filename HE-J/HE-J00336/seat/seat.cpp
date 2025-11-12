#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int z=0;
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n=0,m=0,r=0,k=1,l=1;
int a[110];
int b[110][110];
cin>>n>>m;
for(int i=1;i<=n*m;++i){
	cin>>a[i];
}
l=1;
r=a[1];
sort(a,a+110,cmp);

	if(k%2!=0){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=k;++j){
			b[i][j]=a[z];
			z++;
			}
			
		}
		k++;
		l++;
	}
	 if(k%2==0){
		for(int i=n;i>=1;--i){
			for(int j=k;j<=k;j++){
				b[i][j]=a[z];
				z++;
				
			}
			
		}
		l++;
		k++;

}

for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(b[i][j]==r) cout<<i<<" "<<j;
	}
}


return 0;
} 
