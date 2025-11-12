#include <bits/stdc++.h>
using namespace std;
void club(){
	int n,r,x=0,y=0,z=0,s=0;
	cin>>n;
	int a[n][3],b[n][3],c[n][3],d[n],e[n],f[n][3];
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			c[i][j]=a[i][j];
			b[i][j]=2;
		}
		d[i]=n-1;
	}
	for(int m=0;m<n;m++){
		for(int i=0;i<3;i++){
			for(int j=i;j<3;j++){
				if(c[m][i]<c[m][j]){
					x=c[m][i];
					c[m][i]=c[m][j];
					c[m][j]=x;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			if(c[i][0]==a[i][j]){
				f[i][0]=j;
			}
			if(c[i][1]==a[i][j]){
				f[i][1]=j;
			}
			if(c[i][2]==a[i][j]){
				f[i][2]=j;
			}
		}
	}

	x=0;
	for(int m=0;m<n;m++){
		for(int i=0;i<n;i++){
			if(c[m][0]<c[i][0]){
				d[m]--;
			}
		}
	}
	for(int i=0;i<n;i++){
		x=-1;
		for(int m=0;m<n;m++){
			if(x<d[m]){
				x=d[m];
				e[i]=m;
			}
		}
		d[e[i]]=-2;
	}

	for(int m=0;m<n;m++){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(a[m][i]>a[m][j]){
					b[m][i]--;
				}
			}
		}
	}
	x=0;
	for(int j=0;j<n;j++){
		r=0;
		if(x+1>n/2){
			if(b[e[j]][1]<b[e[j]][2]){
				r=1;
			}
			else{
				r=2;
			}
		}
		else{
			if(y+1>n/2){
				if(b[e[j]][0]<b[e[j]][2]){
					r=0;
				}
				else{
					r=2;
				}
			}
			else{
				if(z+1>n/2){
					if(b[e[j]][0]<b[e[j]][1]){
						r=0;
					}
					else{
						r=1;
					}
				}
				else{
					if(b[e[j]][0]<b[e[j]][1] and b[e[j]][0]<b[e[j]][2]){
						if(j!=n-1 and a[e[j+1]][0]==a[e[j+1]][f[e[j]][0]] and a[e[j]][0]+a[e[j+1]][f[e[j]][1]]<a[e[j]][f[e[j]][1]]+a[e[j+1]][f[e[j]][0]] and x+2>n/2){
							r=f[e[j]][1];
						}
						else{
							r=0;
						}
						
					}
					if(b[e[j]][1]<b[e[j]][2] and b[e[j]][1]<b[e[j]][0]){
						if(j!=n-1 and a[e[j+1]][1]==a[e[j+1]][f[e[j]][1]] and a[e[j]][1]+a[e[j+1]][f[e[j]][1]]<a[e[j]][f[e[j]][1]]+a[e[j+1]][f[e[j]][0]] and y+2>n/2){
							r=f[e[j]][1];
						}
						else{
							r=1;
						}
						
					}
					if(b[e[j]][2]<b[e[j]][1] and b[e[j]][2]<b[e[j]][0]){
						if(j!=n-1 and a[e[j+1]][2]==a[e[j+1]][f[e[j]][2]] and a[e[j]][2]+a[e[j+1]][f[e[j]][1]]<a[e[j]][f[e[j]][1]]+a[e[j+1]][f[e[j]][0]] and z+2>n/2){
							r=f[e[j]][1];
						}
						else{
							r=2;
						}
						
					}
				}
			}
		}
		s+=a[e[j]][r];
		if(r==0){
			x++;
		}
		if(r==1){
			y++;
		}
		if(r==2){
			z++;
		}
	}
	cout<<s<<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		club();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
