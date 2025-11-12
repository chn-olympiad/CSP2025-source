#include<bits/stdc++.h>
using namespace std;
struct l{
	int i,j,k;
}x[100001],y[100001],z[100001];
int t,n,s,xx,yy,zz;
bool cmpx(l n,l m){
	return max(n.j,n.k)-n.i>max(m.j,m.k)-m.i;
}
bool cmpy(l n,l m){
	return max(n.k,n.i)-n.j>max(m.k,m.i)-m.j;
}
bool cmpz(l n,l m){
	return max(n.i,n.j)-n.k>max(m.i,m.j)-m.k;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		s=0;
		xx=0;
		yy=0;
		zz=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				x[++xx].i=a;
				x[xx].j=b;
				x[xx].k=c;
				s+=a; 
			}else if(b>=c&&b>=a){
				y[++yy].i=a;
				y[yy].j=b;
				y[yy].k=c;	
				s+=b;
			}else{
				z[++zz].i=a;
				z[zz].j=b;
				z[zz].k=c;
				s+=c;
			}
		}
		if(xx<=n/2&&yy<=n/2&&zz<=n/2){
			cout<<s<<endl;
		}else if(xx>=n/2){
			sort(x+1,x+1+xx,cmpx);
			for(int i=1;i<=xx-n/2;i++){
				s+=max(x[i].j,x[i].k)-x[i].i;
			}
			cout<<s<<endl;
		}else if(yy>=n/2){
			sort(y+1,y+1+yy,cmpy);
			for(int i=1;i<=yy-n/2;i++){
				s+=max(y[i].k,y[i].i)-y[i].j;
			}
			cout<<s<<endl;
		}else if(zz>=n/2){
			sort(z+1,z+1+zz,cmpz);
			for(int i=1;i<=zz-n/2;i++){
				s+=max(z[i].i,z[i].j)-z[i].k;
			}
			cout<<s<<endl;
		}
	}
	
	return 0;
}  
