#include<bits/stdc++.h>
using namespace std;
int t,n,ans,i,j,f;
struct z{
	int x,c,v;
}a[100010];
void d(int s,int x1,int w,int y1,int e,int z1,int r){
	if(s==n+1){
	    if(w<=f&&e<=f&&r<=f){
		    ans=max(ans,x1+y1+z1);	
		}
		return;	
	}
    if(w>f||e>f||r>f){
	    return;	
	}
	d(s+1,x1+a[s].x,w+1,y1,e,z1,r);
	d(s+1,x1,w,y1+a[s].c,e+1,z1,r);
	d(s+1,x1,w,y1,e,z1+a[s].v,r+1);
	return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i].x>>a[i].c>>a[i].v;
		}
		f=n/2;
		ans=0;
		d(1,0,0,0,0,0,0);
		cout<<ans<<endl;
	}
    return 0;
}
