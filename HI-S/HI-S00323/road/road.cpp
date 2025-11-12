#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[20001];
struct u{
	long long x,y,z,f;
}a[1010001]; 
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int m1(int u1,int u2){
	int fx=find(u1);
	int fy=find(u2);
	if(fx!=fy)f[fx]=fy;
}
int cmp(u u1,u u2){
	return u1.z<u2.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=2*n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].f=-1;
	}
	int m11=m;
	for(int i=1;i<=k;i++){
		long long c,c1;
		cin>>c1;
		
		for(int j=1;j<=n;j++){
			cin>>c;
			m++;
			a[m].f=c1;
			a[m].x=i+m11;
			a[m].y=j;
			a[m].z=c+c1;
		}
	}
	sort(a+1,a+m+1,cmp);
	long long s=0,sum=0;
	for(int i=1;i<=m;i++){
		int fx=find(a[i].x);
		int fy=find(a[i].y);
		if(fx!=fy){
			m1(fx,fy);
			if(a[i].f==-1)sum+=a[i].z;
			else{
				int uz=a[i].f;
				n++;
				sum+=a[i].z;
				for(int j=1;j<=m;j++){
					if(a[j].f==uz)a[j].f=-1,a[j].z-=uz;
				}
			}
		
			s++;
		}
		if(s==n-1){
			
			break;
		}
	}
	cout<<sum;
	return 0;
} 
