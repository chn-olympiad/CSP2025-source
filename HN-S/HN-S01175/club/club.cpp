#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,m[1005][5],p[1005],x[1005],y[2005],z[2005],hx[2005]={0},hy[2005]={0},hz[2005]={0},g,a=0,zm[10];
	long long n;
	int v=0,k=0,s=0;
	cin>>t;
	for(int q=1;q<=t;q++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>m[i][j];
			}
			if(max(max(m[i][1],m[i][2]),m[i][3])==m[i][1]){
				hx[i]=i;
			}
			else if(max(max(m[i][1],m[i][2]),m[i][3])==m[i][2]){
				hy[i]=i;
			}
			else{
				hz[i]=i;
			}
		}
		for(int i=1;i<=n;i++){
			
			if(hx[i]!=0){
				x[v]=m[i][1];
				v++;
			}
			if(hy[i]!=0){
				y[k]=m[i][2];
				k++;
			}
			if(hy[i]!=0){
				z[s]=m[i][3];
				s++;
			}
		}
		sort(x,x+v);
		if(v<=n/2){
			for(int i=v;i>=0;i--){
				a+=x[i];
			}
		}
		else{
			for(int i=n/2;i>=0;i--){
				a+=x[i];
				g=v-(n/2);
			}
		}
		for(int j=g;j<=v;j++){
			for(int i=1;i<=n;i++){
				if(m[i][1]==x[j]){
					y[k+i]=m[i][2];
				}
			}
		}
		sort(y,y+k+g);
		if(k+g<=n/2){
			for(int i=k+g;i>=0;i--){
				a+=y[i];
			}
		}
		else{
			for(int i=n/2;i>=0;i--){
				a+=x[i];
				g=v+g-(n/2);
			}
		}
		for(int j=g;j<=k;j++){
			for(int i=1;i<=n;i++){
				if(m[i][2]==y[j]){
					z[s+i]=m[i][3];
				}
			}
		}
		sort(z,z+s+g);
		for(int i=s+g;i>=0;i--){
			a+=z[i];
		}
		zm[t]=a;
	}
	for(int i=1;i<=t;i++){
		cout<<zm[t]<<endl;
	}
	return 0;
} 
