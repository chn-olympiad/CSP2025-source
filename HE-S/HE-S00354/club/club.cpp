#include<bits/stdc++.h>
using namespace std;
int n,a[100010][3],t,c[100010],h[3][100010],s,mem[100010],b[3];
int maxx(int x,int y,int z){
	if(x>=y&&x>=z)return x;
	if(y>=x&&y>=z)return y;
	if(z>=y&&z>=x)return z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k];
				if(a[j][k]==maxx(a[j][0],a[j][1],a[j][2])){
					mem[j]=k;
				}
			}
			b[mem[j]]++;
			s+=maxx(a[j][0],a[j][1],a[j][2]);
		}
		for(int k=0;k<3;k++){
			if(b[k]==maxx(b[0],b[1],b[2])){
				for(int j=1;j<=n;j++){
					if(mem[j]==k){
						c[j]=max(a[j][0],a[j][1])+max(a[j][0],a[j][2])+max(a[j][1],a[j][2])-3*maxx(a[j][0],a[j][1],a[j][2]);
					}
				}
				break;
			}
		}
		sort(c,c+100010);
		for(int j=n/2;j<=n;j++){
			s+=c[j];
		}
		cout<<s;
		s=0;
		for(int j=0;j<=n;j++){
			c[j]=0;
		}
	}
	return 0;
}
