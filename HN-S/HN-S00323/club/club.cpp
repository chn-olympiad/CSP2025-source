#include<bits/stdc++.h>
using namespace std;
struct zzz{
	int a1;
	int a2;
};
zzz a[100005][4];
int T,n,b[100005][3],z1,z2,z3,m=1000000,x1[100005],x2[100005],x3[100005],y,sum,s;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		z1=z2=z3=0;
		sum=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				cin>>a[i][j].a1;
			}
			if (a[i][1].a1>a[i][2].a1){
				if (a[i][1].a1>a[i][3].a1){
					a[i][1].a2=1;
					if (a[i][2].a1>a[i][3].a1){
						a[i][2].a2=2;
						a[i][3].a2=3;
					}else {
						a[i][3].a2=2;
						a[i][2].a2=3;
					}
				}else {
					a[i][1].a2=2;
					a[i][2].a2=3;
					a[i][3].a2=1;
				}
			}else{
					if (a[i][2].a1>a[i][3].a1){
						a[i][2].a2=1;
						if (a[i][1].a1>a[i][3].a1){
							a[i][1].a2=2;
							a[i][3].a2=3;
						}else {
							a[i][3].a2=2;
							a[i][1].a2=3;
						}
					}else {
						a[i][1].a2=3;
						a[i][2].a2=2;
						a[i][3].a2=1;
					}
				}
		}
		for (int i=1;i<=n;i++){
			if (a[i][1].a2==1){
				z1++;
				x1[z1]=i;
				if (a[i][2].a2==2){
					b[i][1]=a[i][1].a1-a[i][2].a1;
					b[i][2]=a[i][2].a1-a[i][3].a1;
				}else {
					b[i][1]=a[i][1].a1-a[i][3].a1;
					b[i][2]=a[i][3].a1-a[i][2].a1;
				}
			}else if (a[i][2].a2==1){
				z2++;
				x2[z2]=i;
				if (a[i][1].a2==2){
					b[i][1]=a[i][2].a1-a[i][1].a1;
					b[i][2]=a[i][1].a1-a[i][3].a1;
				}else {
					b[i][1]=a[i][2].a1-a[i][3].a1;
					b[i][2]=a[i][3].a1-a[i][1].a1;
				}
			}else if (a[i][3].a2==1){
				z3++;
				x3[z3]=i;
				if (a[i][1].a2==2){
					b[i][1]=a[i][3].a1-a[i][1].a1;
					b[i][2]=a[i][1].a1-a[i][2].a1;
				}else {
					b[i][1]=a[i][3].a1-a[i][2].a1;
					b[i][2]=a[i][2].a1-a[i][1].a1;
				}
			}
		}
		for (;z1>n/2||z2>n/2||z3>n/2;){
			if (z1>n/2){
				while(z1!=n/2){
					m=100000;
					y=0;
					for (int i=1;i<=z1;i++){
						if (b[x1[i]][1]<m){
							m=b[x1[i]][1];
							y=x1[i];
							s=i;
						}
					}
					for (int i=1;i<=z1;i++){
						if (i==s){
							x1[i]=0;
						}
						if (i>s){
							x1[i-1]=x1[i];
							x1[i]=0;
						}
					}
					z1--;
					if (a[y][2].a2==2){
						z2++;
						x2[z2]=y;
					}else {
						z3++;
						x3[z3]=y;
					}
				}
			}else if (z2>n/2){
				while(z2!=n/2){
					m=100000;
					y=0;
					for (int i=1;i<=z2;i++){
						if (b[x2[i]][1]<m){
							m=b[x2[i]][1];
							y=x2[i];
							s=i;
						}
					}
					for (int i=1;i<=z2;i++){
						if (i==s){
							x2[i]=0;
						}
						if (i>s){
							x2[i-1]=x2[i];
							x2[i]=0;
						}
					}
					z2--;
					if (a[y][1].a2==2){
						z1++;
						x1[z1]=y;
					}else {
						z3++;
						x3[z3]=y;
					}
				}
			}else if (z3>n/2){
				while(z3!=n/2){
					m=100000;
					y=0;
					for (int i=1;i<=z3;i++){
						if (b[x3[i]][1]<m){
							m=b[x3[i]][1];
							y=x3[i];
							s=i;
						}
					}
					for (int i=1;i<=z3;i++){
						if (i==s){
							x3[i]=0;
						}
						if (i>s){
							x3[i-1]=x3[i];
							x3[i]=0;
						}
					}
					z3--;
					if (a[y][2].a2==2){
						z2++;
						x2[z2]=y;
					}else {
						z1++;
						x1[z1]=y;
					}
				}
			}
		}
		for (int i=1;i<=z1;i++){
			sum+=a[x1[i]][1].a1;
		}
		for (int i=1;i<=z2;i++){
			sum+=a[x2[i]][2].a1;
		}
		for (int i=1;i<=z3;i++){
			sum+=a[x3[i]][3].a1;
		}
		cout<<sum;
	}
	return 0;
} 
