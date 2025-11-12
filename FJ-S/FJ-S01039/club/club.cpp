#include<bits/stdc++.h>
using namespace std;
int n;
struct k{
	int x,y,z;
}a[100007];

bool cmp1(k a,k b){
	return (a.x-max(a.z,a.y)>b.x-max(b.z,b.y));
}
bool cmp2(k a,k b){
	return a.z!=-1&&(a.y-max(a.x,a.z)>b.y-max(b.x,b.z));
//	return a.y>b.y;
}
bool cmp3(k a,k b){
	return a.z>0&&(a.z-max(a.x,a.y)>b.z-max(b.x,b.y));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	k oh;
	oh.x=-1;
	oh.y=-1;
	oh.z=-1;
	scanf("%d",&t);
	while(t--){int u=0,b=0,c=0,f1,f2,f3=1;
		long long ans=0;	
			scanf("%d",&n);int p=n/2;
		for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		if(a[i].z!=0)f3=0;
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=p;i++){
			if(a[i].x==max(a[i].x,max(a[i].y,a[i].z))||f3){
				ans+=a[i].x;u++;
			//	printf("%d ",a[i].x);
				a[i]=oh;
				
			}
		//	else p++;
		}
		p=n/2;
	//	cout<<u<<' '; 
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n/2;i++){
			if(a[i].x==-1){
			//	p++;
				continue;
			}

			if(a[i].y==max(a[i].y,a[i].z)){
				ans+=a[i].y;	//printf("%d ",a[i].y);
				a[i]=oh;b++;
			}
		}//cout<<b;
		if(u+b==n){
			printf("%lld\n",ans);
			continue;
		}
			sort(a+1,a+1+n,cmp3);
		for(int i=1;i<=n;i++){
			if(a[i].x==-1)continue;
		//	cout<<a[i].z;
			//&&a[i].z==max(a[i].x,max(a[i].y,a[i].z))
			if(i<=n/2&&a[i].z!=0){
				ans+=a[i].z;//	printf("%d ",a[i].z);
				a[i]=oh;
			}
			else{//cout<<max(a[i].x,a[i].y)<<' ';
				if(u<p&&b<p){
					if(max(a[i].x,a[i].y)==a[i].x)u++;
					else b++;
				ans+=max(a[i].x,a[i].y);	
				
				}
				else if(u<p)a[i].x,u++;
				else if(b<p)ans+=a[i].y,b++;		//	printf("%d ",max(a[i].x,a[i].y));
				a[i]=oh;
			}
				
		}
		printf("%d\n",ans);
	}

} 
