#include<bits/stdc++.h>
using namespace std;
struct Lie{
	int x,i;
};
struct Hang{
	int x,j;
};
int is[4],T,n,ans,hl[1000006],b[1000006][4],cha[1000006];
Hang hang[1000006][4],a[1000006][4];
Lie lie[4][1000006];
bool cmp1(Lie a,Lie b){
		return a.x>b.x;
}
bool cmp2 (Hang a,Hang b){
		return a.x>b.x;
}

//bool cmp2 (Hang a,Hang b){
//	int x[4],y[4];
//	x[1]=a.a,x[2]=a.b,x[3]=a.c;
//	y[1]=b.a,y[2]=b.b,y[3]=b.c;
//	sort(x+1,x+4);
//	sort(y+1,y+4);
//	for(int i=1;i<=3;i++){
//		if(x[i]!=y[i])
//			return x[i]<y[i];
//	}
//	return 0;
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	scanf("%d",&T);
	for(;T--;){
		ans=0;
		memset(lie,0,sizeof(lie));
		memset(hang,0,sizeof(hang));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(is,0,sizeof(is));
		memset(hl,0,sizeof(hl));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int x;
//				printf("1");
				scanf("%d",&x);
				lie[j][i].x=x;
				lie[j][i].i=i;
				
//				if(j==1)
//					hang[j].a=x;
//				if(j==2)
//					hang[j].b=x;
//				if(j==3)
//					hang[j].c=x;
				hang[i][j].x=x;
				hang[i][j].j=j;
				a[i][j].x=x;
				a[i][j].j=j;
			}
		}
//		printf("%d",lie[2][1].x);
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+4,cmp2);
		}
		for(int i=1;i<=n;i++)
			cha[i]=a[i][1].x-a[i][2].x;
//		for(int i=1;i<=n;i++)
//			printf("%d",a[i][1]);
		for(int i=1;i<=n;i++){
			is[a[i][1].j]++;
		}
//		printf("^%d ",is[1]);
		int f=0;
		for(int i=1;i<=3;i++){
			if(is[i]>n/2){
				f=i;
//				sort(lie[i]+1,lie[i]+n+1,cmp1);
			}
		}
//		printf("!%d",f);
		for(int i=1;i<=n;i++)
			ans+=a[i][1].x;
		if(f==0){
			
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i][1].j!=f){
				cha[i]=INT_MAX;
			}
		}
		
		sort(cha+1,cha+n+1);
//		for(int i=1;i<=n;i++)
//			printf("%d ",lie[f][i]);
//		for(int i=n/2+1;i<=is[f];i++)
//			hl[lie[f][i].i]++;
		int l=is[f]-n/2,len=0;
//		for(int i=1;i<=n;i++)
//			printf("%d ",cha[i]);
//		printf("@%d",l);	
		for(int i=1;i<=l;i++)
			ans-=cha[i];
		
		printf("%d\n",ans);
//		for(int i=1;i<=3;i++)
//			printf("%d ",hang[2][i]);
		for(int i=1;i<=n;i++){
			if(hl[i]==1){
				len++;
//				printf("!");
//				printf("^%d",a[i][1].j);
				for(int j=1;j<=3;j++){
					if(j==a[i][1].j){
//						printf("!");
						hang[i][j].x=0;}
//						printf("%d ",[i][j].x);
					b[len][j]=hang[i][j].x;
				}
			}
		}
//		for(int i=1;i<=3;i++)
//			printf("%d ",b[1][i]);
		for(int i=1;i<=l;i++){
			sort(b[i]+1,b[i]+4);
		}
		for(int i=1;i<=l;i++){
			ans+=b[i][3];
		}
//		printf("#%d",l);
//		printf("%d",ans);
		for(int i=1;i<=n/2;i++){
//			printf("%d ",lie[f][i].x);
			ans+=lie[f][i].x;
		}
//		printf("%d\n",ans);
	}
	return 0;
}
