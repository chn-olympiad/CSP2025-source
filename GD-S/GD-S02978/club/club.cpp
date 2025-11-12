#include<bits/stdc++.h>
using namespace std;
int t,n,a[100007][10],q,w,e,r=1,u=1,y=1,s=0,b[10][100007],o[100007],f=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		r=1;
		u=1;
		y=1;
		s=0;
		f=0;
		b[1][1]=0;
		b[2][1]=0;
		b[3][1]=0;
		for(int j=1;j<=n;j++){
			cin>>q>>w>>e;
			if(q>=w&&w>=e){
				a[j][1]=q;
				a[j][2]=q-w;
				a[j][3]=e;
			}
			else if(q>=e&&e>=w){
				a[j][1]=q;
				a[j][2]=q-e;
				a[j][3]=w;
			}
			else if(e>=w&&w>=q){
				a[j][1]=e;
				a[j][2]=e-w;
				a[j][3]=q;
			}
			else if(e>=q&&q>=w){
				a[j][1]=e;
				a[j][2]=e-q;
				a[j][3]=w;
			}
			else if(w>=q&&q>=e){
				a[j][1]=w;
				a[j][2]=w-q;
				a[j][3]=e;
			}
			else{
				a[j][1]=w;
				a[j][2]=w-e;
				a[j][3]=q;
			}
			s+=a[j][1];
			if(a[j][1]==q){
				b[1][1]++;
				r++;
				b[1][r]=j;
			}
			else if(a[j][1]==w){
				b[2][1]++;
				y++;
				b[2][y]=j;
			}
			else if(a[j][1]==e){
				b[3][1]++;
				u++;
				b[3][u]=j;
			}
		}
		for(int j=1;j<=3;j++){
			if(b[j][1]>n/2){
				if(j==1){
					for(int k=2;k<=r;k++){
						o[k-1]=a[b[1][k]][2];
					}
					sort(o+1,o+r-1+1);
					for(int k=1;k<=r-1-n/2;k++){
						s-=o[k];
					}
					cout<<s;
					f=1;
				}
				else if(j==2){
					for(int k=2;k<=y;k++){
						o[k-1]=a[b[2][k]][2];
					}
					sort(o+1,o+y-1+1);
					for(int k=1;k<=y-1-n/2;k++){
						s-=o[k];
					}
					cout<<s;
					f=1;
				}
				else if(j==3){
					for(int k=2;k<=u;k++){
						o[k-1]=a[b[3][k]][2];
					}
					sort(o+1,o+u-1+1);
					for(int k=1;k<=u-1-n/2;k++){
						s-=o[k];
					}
					cout<<s;
					f=1;
				}
				
			}
		}
		if(f==0){
			cout<<s;
		}
		cout<<endl;
	}
	return 0;
}
