#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],b[100005][5],k,q[5],r,l,p,o,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			r=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]>r){
					r=a[i][j];
					l=j;
				}
			}
			k+=r;
			q[l]++;
		}
		p=0;
		for(int i=1;i<=3;i++){
			if(q[l]>n/2){
				p=1;
				o=l;
			}
		}
		if(p){
			for(int z=1;z<=q[o]-n/2;z++){
				m=0;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=3;j++){
						if(j!=o){
							m=min(a[i][o]-a[i][j],m);
						}
					}
				}
				k-=m;
			}
		}
		cout<<k<<'\n';
	}
}
