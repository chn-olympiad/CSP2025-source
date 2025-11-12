#include<bits/stdc++.h>
using namespace std;
int T,n;
struct jie{
	int zu;
	int yi,er,san;
	int ge;
}a[114514],b[114514],c[114514];
bool cmp(jie x,jie y){
	return x.yi>y.yi;
}
bool cmp12(jie x,jie y){
	return x.er>y.er;
}
bool cmp13(jie x,jie y){
	return x.san>y.san;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		
		int qwe=1,yig=0,erg=0,sang=0,p1=0,p2=0,id1=1,id2=1,id3=1;
		long long he=0;
		cin>>n;
		for(int i=1,x,y,z;i<=n;i++){
			cin>>x>>y>>z;
			a[i].ge=i;
			b[i].ge=i;
			c[i].ge=i;
			a[i].yi=x;
			a[i].er=y;
			a[i].san=z;
			b[i].yi=x;
			b[i].er=y;
			b[i].san=z;
			c[i].yi=x;
			c[i].er=y;
			c[i].san=z;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp12);
		sort(c+1,c+1+n,cmp13);
		for(int i=1;i<=n;i++){
			while(id1<=n){
				if(a[id1].yi>b[a[id1].ge].er&&a[id1].yi>c[a[id1].ge].san&&yig<n/2&&a[id1].zu!=1){
					a[id1].zu=1;
					he+=a[id1].yi;
				}
				id1++;
			}
			while(id2<=n){
				if(b[id2].er>a[b[id2].ge].yi&&b[id2].er>c[b[id2].ge].san&&erg<n/2&&a[b[id2].ge].zu!=1){
					a[b[id2].ge].zu=1;
					he+=b[id2].er;
				}
				id2++;
			}
			while(id3<=n){
				if(c[id3].san>a[c[id3].ge].yi&&c[id3].san>b[c[id3].ge].er&&sang<n/2&&a[c[id3].ge].zu!=1){
					a[c[id3].ge].zu=1;
					he+=c[id3].san;
				}
				id3++;
			}
			
		}
		cout<<he;
		for(int i=1;i<=n;i++){
			a[i].ge=0;
			b[i].ge=0;
			c[i].ge=0;
			a[i].yi=0;
			a[i].er=0;
			a[i].san=0;
			b[i].yi=0;
			b[i].er=0;
			b[i].san=0;
			c[i].yi=0;
			c[i].er=0;
			c[i].san=0;
		}
	}
	
	return 0;
}
