#include <bits/stdc++.h>
using namespace std;
int n,m,f,g,h,ff,gg,hh;
struct hhh{
	int w;int x;int y;int z;int hao;
}a[100010],b[100010],c[100010];
bool cmp(hhh x,hhh y){
	return x.z>y.z;
}
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		int cnt=0;
		gg=hh=ff=0;
		for(int j=1;j<=m;j++){
		    scanf("%d%d%d",&f,&g,&h);
		    int x=max(f,max(g,h)),cnt=0;
		    if(x==f){a[++ff].z=f;a[ff].hao=j;}
		    else if(x==g){b[++gg].z=g;b[gg].hao=j;}
		    else {c[++hh].z=h;c[hh].hao=j;}
		    a[j].x=b[j].x=c[j].x=f;
		    a[j].y=b[j].y=c[j].y=g;
		    a[j].w=b[j].w=c[j].w=h;
	    }
	    if(ff>m/2){
	    	sort(a+1,a+ff+1,cmp);
	    	for(int k=ff-(m/2);k<=ff;k++){
	    		cnt+=max(a[k].w,a[k].y);
	    	}ff-=(m/2);
	    	//cout<<cnt<<'\n';
	    }else if(gg>m/2){
	    	sort(b+1,b+gg+1,cmp);
	    	for(int k=gg-(m/2);k<=gg;k++){
	    		cnt+=max(b[k].x,b[k].w);
	    	}gg-=(m/2);//cout<<cnt<<'\n';
	    }else if(hh>m/2){
	    	sort(c+1,c+hh+1,cmp);
	    	for(int k=hh-(m/2);k<=hh;k++){
	    		cnt+=max(c[k].x,c[k].y);
	    	}hh-=(m/2);//cout<<cnt<<'\n';
	    }
		for(int k=1;k<=ff;k++)cnt+=a[k].z;
	    for(int k=1;k<=gg;k++)cnt+=b[k].z;
	    for(int k=1;k<=hh;k++)cnt+=c[k].z;
	    printf("%d",cnt);
	}
	return 0;
}
