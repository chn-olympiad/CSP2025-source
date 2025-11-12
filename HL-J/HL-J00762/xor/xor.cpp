#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ansn,sumn;
struct xorn{
	int x,y;
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	xorn f[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			
			sumn=a[i];
			for(int h=i+1;h<=j;h++){
				sumn^=a[h];
			}if(sumn==k){
				f[i].x=i;
				f[i].y=j;
				//cout<<i<<" "<<j<<endl;
				ansn++;
				for(int h=1;h<i;h++){
					if((f[i].x>=f[h].x && f[i].x<=f[h].y) || (f[i].y>=f[h].x && f[i].y<=f[h].y)){
						ansn--;
						break; 
					}
				}
			}
		}
	}
	cout<<ansn;
	return 0;
}
