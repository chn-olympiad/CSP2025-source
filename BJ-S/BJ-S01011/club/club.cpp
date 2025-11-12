#include<bits/stdc++.h>
using namespace std;

int t,n,a[100015][3],bm[3],minid[3],v=0;
int b[3][50015],g[3];
long long ans;

//struct lf{
//	int id,n;
//};
//lf nu[3][100015];

int check(int id){
	if(max(max(a[id][0],a[id][1]),a[id][2])==a[id][0]) return 0;
	if(max(max(a[id][0],a[id][1]),a[id][2])==a[id][1]) return 1;
	if(max(max(a[id][0],a[id][1]),a[id][2])==a[id][2]) return 2;
}

bool h(int i,int tem,int miid){
	if(tem==0){
		if(a[i][tem]+max(a[b[tem][miid]][1],a[b[tem][miid]][2])>a[b[tem][miid]][tem]+max(a[i][1],a[i][2])) return true;
	}
	if(tem==1){
		//printf("bool-h 新=%d 不换=%d\n",a[i][tem]+max(a[b[tem][miid]][0],a[b[tem][miid]][2]),a[b[tem][miid]][tem]+max(a[i][0],a[i][2]));
		if(a[i][tem]+max(a[b[tem][miid]][0],a[b[tem][miid]][2])>a[b[tem][miid]][tem]+max(a[i][0],a[i][2])) return true;
	}
	if(tem==2){
		if(a[i][tem]+max(a[b[tem][miid]][1],a[b[tem][miid]][0])>a[b[tem][miid]][tem]+max(a[i][1],a[i][0])) return true;
	}
	//a[i][tem]+max(a[b[tem][miid]][0],a[b[tem][miid]][1])
	return false;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		ans=0;
		n=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<=2;j++){
				a[i][j]=0;
				b[j][i]=0;
				g[j]=0;
			}
		}
		for(int i=0;i<=2;i++){
			bm[i]=(n+1)/2;
		}
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		for(int i=0;i<n;i++){
			//printf("for开头的i=%d\n",i);
			int tem=check(i);
			if(bm[tem]>0){//还能放
				//printf("%d tem=%d\n",bm[tem],tem);
				ans+=a[i][tem];
				//printf("ans+=%d ans=%d\n",a[i][tem],ans);
				bm[tem]--;
				b[tem][g[tem]-1]=i;//存放id
				g[tem]++;
			}else{//放不了了
				int miid=-1;
					//debug start
				//printf("-----debug-----\n");
				//for(int j=0;j<g[tem];j++){printf("%d ",a[b[tem][j]][tem]);}
				//printf("\n-----debug-----\n");
					//debug end
				for(int j=0;j<g[tem];j++){//找到好感最低的那个
					//printf("j=%d找ing=%d",j,a[b[tem][j]][tem]);
					if(miid==-1){
						miid=j;
						//printf("内miid=%d\n",b[tem][miid]);
					}else if(a[b[tem][miid]][tem]>a[b[tem][j]][tem]){
						miid=j;
						//printf("内-miid=%d j=%d\n",b[tem][miid],j);
					}
				}
				//cout<<a[b[tem][miid]][tem]<<' '<<a[i][tem]<<endl;
				if(h(i,tem,miid)){//a[b[tem][miid]][tem]<a[i][tem]
					
					ans-=a[b[tem][miid]][tem];
					ans+=a[i][tem];
					a[b[tem][miid]][tem]=-1;
//					recheck(b[tem][miid]);//重新分配
					v=i;
					i=b[tem][miid]-1;
					//printf("miid=%d continue\n",b[tem][miid]);
					b[tem][miid]=v;//替换	
					continue;			
				}else{
					//printf("debug!!! %d %d\n",a[b[tem][miid]][tem],a[i][tem]);
					//printf("\ndebug-2 %d",a[b[tem][miid]][tem]);
					a[i][tem]=-1;
					i--;
					
				}
			}
			//printf("i=%dans=%d\n",i,ans);
			if(v!=0){
				i=v;
				//printf("v=%d i=%d\n",v,i);
				v=0;
			}
		}
		printf("%lld\n",ans);
	}
		
	
	return 0;
}
