#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[100000][3],m[100000];
long long t,n,g[3],s=0,lx=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int w=0;w<t;w++){
		cin>>n;
		s=0;
		g[0]=0;
		g[1]=0;
		g[2]=0;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]){
				g[0]++;
				s+=a[i][0];
				m[i]=a[i][0]-max(a[i][1],a[i][2]);
			}
			else if(a[i][1]>a[i][2]){
				g[1]++;
				s+=a[i][1];
				m[i]=a[i][1]-max(a[i][0],a[i][2])+100000;
			}
			else{
				g[2]++;
				s+=a[i][2];
				m[i]=a[i][2]-max(a[i][0],a[i][1])+200000;
			}
		}
		sort(m,m+n);
		for(int z=0;z<3;z++){
			if(g[z]>n/2){
				while(m[lx]<z*100000){
					lx++;
				}
				for(int i=lx;i<lx+g[z]-n/2;i++){
					s-=m[i]-z*100000;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
