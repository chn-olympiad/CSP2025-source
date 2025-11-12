//GZ-S00493 毕节梁才学校 韩昌辰 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ret=0;
	char ch=' ',c=getchar();
	while(!('0'<=c&&c<='9')) ch=c,c=getchar();
	while('0'<=c&&c<='9') ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
	return ch=='-'?-ret:ret;
}
struct STU{
	int x,y,z,ma,which;
}st[100010];
int T,n,ans,s;
int content[5];//每个社团目前人数 
int kou[100010];//扣除满意度 
void init(){
	ans=0;
	s=0;
	n=0;
	memset(st,0,sizeof(st));
	memset(content,0,sizeof(content));
	memset(kou,0,sizeof(kou));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T>=0){
		init();
		T--;
		n=read();
		for(int i=1;i<=n;i++){
			int xx,yy,zz,ma,wh;
			xx=read();
			yy=read();
			zz=read();
			wh=max(xx,yy);
			wh=max(wh,zz);
			ma=wh;
			if(ma==xx) wh=1,content[1]++;
			else if(ma==yy) wh=2,content[2]++;
			else wh=3,content[3]++;
			ans+=ma;
			st[i]=(STU){xx,yy,zz,ma,wh};
		}
		if(content[1]<=n/2&&content[2]<=n/2&&content[3]<=n/2) printf("%d\n",ans);
		else{
			int jian;
			if(content[1]>n/2){
				jian=content[1]-n/2;
				for(int j=1;j<=n;j++){
					if(st[j].which==1) s++,kou[s]=min(st[j].x-st[j].y,st[j].x-st[j].z);
				}
				sort(kou+1,kou+s+1);
				for(int j=1;j<=jian;j++) ans-=kou[j];
			}else if(content[2]>n/2){
				jian=content[2]-n/2;
				for(int j=1;j<=n;j++){
					if(st[j].which==2) s++,kou[s]=min(st[j].y-st[j].x,st[j].y-st[j].z);
				}
				sort(kou+1,kou+s+1);
				for(int j=1;j<=jian;j++) ans-=kou[j];
			}else{
				jian=content[3]-n/2;
				for(int j=1;j<=n;j++){
					if(st[j].which==3) s++,kou[s]=min(st[j].z-st[j].y,st[j].z-st[j].x);
				}
				sort(kou+1,kou+s+1);
				for(int j=1;j<=jian;j++) ans-=kou[j];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
