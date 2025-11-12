//GZ-S00241 安顺市第二高级中学 李舜杰 
#include<bits/stdc++.h>
#define N 100005
typedef long long  LL;
using namespace std;
struct node{
	LL w,id;
}bm[N];
LL t,n,a[N],b[N],c[N];
LL ma1[N],ma2[N],pl1[N],max1,max2,max3;
LL top;
bool cmp(node x,node y){
	return x.w>y.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie();cout.tie();
	cin>>t;
	while(t--){
		LL ans=0;max1=0;max2=0;max3=0;top=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
	        if(a[i]>b[i]){
	        	if(a[i]>c[i]){
	        		ma1[i]=a[i];pl1[i]=1;max1++;
	        		if(b[i]>c[i]){
	        			ma2[i]=b[i];
					}else{
						ma2[i]=c[i];
					}
				}else{
					ma1[i]=c[i];pl1[i]=3;max3++;
					ma2[i]=a[i];
				}
			}else{
	        	if(b[i]>c[i]){
	        		ma1[i]=b[i];pl1[i]=2;max2++;
	        		if(a[i]>c[i]){
	        			ma2[i]=a[i];
					}else{
						ma2[i]=c[i];
					}
				}else{
					ma1[i]=c[i];pl1[i]=3;max3++;
					ma2[i]=b[i];
				}				
			}
		}
		if(max1<=n/2&&max2<=n/2&&max3<=n/2){
			for(int i=1;i<=n;i++){
				ans+=ma1[i];
			}
			cout<<ans<<endl;
		}else{
			int tpp;
			if(max1>n/2) tpp=1;
			if(max2>n/2) tpp=2;
			if(max3>n/2) tpp=3;
			for(int i=1;i<=n;i++){
				if(pl1[i]==tpp){
					bm[++top].w=ma1[i]-ma2[i];
					bm[top].id=i;
				}else{
					ans+=ma1[i];
				}
			}
			sort(bm+1,bm+1+top,cmp);
			for(int i=1;i<=top;i++){
				if(i<=n/2){
					ans+=ma1[bm[i].id];
				}else{
					ans+=ma2[bm[i].id];
				}
			}
			cout<<ans<<endl;	
		}
	}
	
	return 0;
}

