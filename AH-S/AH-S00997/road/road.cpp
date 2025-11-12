#include<bits/stdc++.h>
using namespace std;
int n,ans,i,j,m,b,s,r1,r2,k,p;
int f[10010];
int c[10010][100],d[10010];
struct z{
	int x,y,v;
}a[100010];
int fi(int w){
	if(f[w]==w){
		return w;
	}else{
	    return fi(f[w]);	
	}
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>b;
	for(i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].v;
		f[i]=i;
	}
	for(i=1;i<=b;i++){
		int o=1;
	    for(j=1;j<=n+1;j++){
		    cin>>c[i][j];
		    if(c[i][j]!=0){
			    o=0;	
			}	
		}
		if(o==1){
		    p=2;	
		}	
	}
	if(p==2){
	    cout<<"0"<<endl;
	    return 0;	
	}	
	ans=0;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			s=INT_MAX;
			r1=fi(i);
			r2=fi(j);
		    for(k=1;k<=m;k++){
                if(a[k].x==r2&&a[k].y==r1){
				    s=min(s,a[k].v);	
				}else if(a[k].x==r1&&a[k].y==r2){
				    s=min(s,a[k].v);	
				}
			}
			for(k=1;k<=b;k++){
			    if(d[i]==0){
					s=min(s,c[k][r1]+c[k][r2]+c[k][1]);
					if(s==c[k][r1]+c[k][r2]+c[k][1]){
					    d[k]=1;	
					}
				}else{
				    s=min(s,c[k][r1]+c[k][r2]);
			    }
			}
			f[r2]=r1;
			ans=ans+s;
			cout<<ans<<endl;
		}
	}
	cout<<ans<<endl;
    return 0;
}
