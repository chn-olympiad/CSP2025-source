#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	long long a=0,b=0,c[100100][3],x=0,y=0,z=0,d[100100],e[100100],f[100100],kl=0;
	cin>>a;
	for(long long i=0;i<a;i++){
		cin>>b;
		for(long long j=1;j<=b;j++){
			cin>>c[j][1]>>c[j][2]>>c[j][3];
			if(max(max(c[j][1],c[j][2]),max(c[j][2],c[j][3]))==c[j][1]){
				d[x]=c[j][1];
				x++;
			}
			if(max(max(c[j][1],c[j][2]),max(c[j][2],c[j][3]))==c[j][2]){
				e[y]=c[j][2];
				y++;
			}
			if(max(max(c[j][1],c[j][2]),max(c[j][2],c[j][3]))==c[j][3]){
				f[z]=c[j][3];
				z++;
			}
		}
		sort(d,d+x);
		sort(e,e+y);
		sort(f,f+z);
		x=0;
		y=0;
		z=0;
		for(long long v=b;v>=0;v--){
			if(max(max(d[v],e[v]),max(e[v],f[v]))==d[v] and x/2<b){
				kl=kl+d[v];
				x++;
			}
			if(max(max(d[v],e[v]),max(e[v],f[v]))==e[v] and y/2<b){
				kl=kl+e[v];
				y++;
			}
			if(max(max(d[v],e[v]),max(e[v],f[v]))==f[v] and z/2<b){
				kl=kl+f[v];
				z++;
			}
		}
		cout<<kl<<endl;
		kl=0;
		x=0;
		y=0;
		z=0;
		b=0;
		for(int i=0;i<100100;i++){
			d[i]=0;
			e[i]=0;
			f[i]=0;
		}
	}
    return 0;
}
