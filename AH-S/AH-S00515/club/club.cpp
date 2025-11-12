#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ggg=0;  scanf("%d",&ggg);
	int n,t1,t2,t3,nx,ny,nz;
	for(int gg=0;gg<ggg;gg++){
		int xx[100009],yy[100009],zz[100009];
		scanf("%d",&n);  long long ans=0,sum=0;
		nx=0; ny=0; nz=0;   //1~n
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&t1,&t2,&t3);
			if(t1>t2&&t1>t3){
				ans+=t1;  nx++;
				if(t2>t3)  xx[nx]=t1-t2;
				else xx[nx]=t1-t3;
			}else if(t2>t1&&t2>t3){
				ans+=t2;  ny++;
				if(t1>t3)  yy[ny]=t2-t1;
				else yy[ny]=t2-t3;
			}else if(t3>t1&&t3>t2){
				ans+=t3;  nz++;
				if(t1>t2)  zz[nz]=t3-t1;
				else zz[nz]=t3-t2;
			}else if(t1==t2&&t1>t3){
				ans+=t1;
				if(nx>ny)  {  nx++;  xx[nx]=0;  }
				else {  ny++;  yy[ny]=0;  }
			}else if(t1==t3&&t1>t2){
				ans+=t1;
				if(nx>nz)  {  nx++;  xx[nx]=0;  }
				else {  nz++;  zz[nz]=0;  }
			}else if(t3==t2&&t2>t1){
				ans+=t3;
				if(ny>nz)  {  ny++; yy[ny]=0;  }
				else {  nz++;  zz[nz]=0;  }
			}else{
				ans+=t1;
			}
		}
		if(nx>(n/2)){
			sort(xx+1,xx+nx+1);
			for(int i=1;i<=nx-(n/2);i++)  sum+=xx[i];
		}if(ny>(n/2)){
			sort(yy+1,yy+ny+1);
			for(int i=1;i<=ny-(n/2);i++)  sum+=yy[i];
		}if(nz>(n/2)){
			sort(zz+1,zz+nz+1);
			for(int i=1;i<=nz-(n/2);i++)  sum+=zz[i];
		}ans-=sum;  printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
