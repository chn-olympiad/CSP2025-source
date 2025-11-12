#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3];
int op[100005];//0->meiyong
int bm[4];//renshu
//int yu[100005];//renyong?
struct  node{
	int m;//ren
	int ha;//manyidu
	int b;//bumen
}s[300005];
bool cmp(node a,node b){
	return a.ha>b.ha;//da  dao  xiao
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int cnt=1;
		long long ans=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				scanf("%d",&a[j][k]);
				s[cnt].m=j,s[cnt].ha=a[j][k],s[cnt++].b=k;
			}
		}
		sort(s+1,s+cnt,cmp);
		//for(int j=1;j<=n*3;j++)cout<<s[j].ha<<" ";
//		for(int j=1;j<=n;j++){
//			if(a[j][1]==0&&a[j][2]==0){
				
				
	//			}
	//	}
		for(int j=1;j<cnt;j++){
			if(op[s[j].m]==0&&bm[s[j].b]+1<=(n/2)){
				op[s[j].m]=s[j].b;
				bm[s[j].b]++;
				ans+=s[j].ha;
				//yu[s[j].m]=1;
			}			
		}
		
	//	for(int j=1;j<=n;j++){
		//	if(op[j]==0){
	//			int qwe;
	//			if(a[j][1]>a[j][2]&&a[j][1]>a[j][3])qwe=1;
	//			else if(a[j][2]>a[j][1]&&a[j][2]>a[j][3])qwe=2;
	//			else if(a[j][3]>a[j][2]&&a[j][3]>a[j][1])qwe=3;
	//			for(int k=1;k<=n;k++){//k->renyuan
	//				if(op[k]==qwe&&k!=j){
	//					if(qwe==1){
	//						if(a[k][qwe]-a[k][qwe+1]<=a[j][qwe]&&a[k][qwe]-a[k][qwe+2]<=a[j][qwe])ans+=(a[j][qwe]-a[k][qwe]+max(a[k][qwe+1],a[k][qwe+2])),k=n,op[k]=a[k][qwe+1]>=a[k][qwe+2]?qwe+1:qwe+2,op[j]=qwe;
	//					}else if(qwe==2){
	//						if(a[k][qwe]-a[k][qwe+1]>=a[j][qwe]&&a[k][qwe]-a[k][qwe-1]>=a[j][qwe])ans+=(a[j][qwe]-a[k][qwe]+max(a[k][qwe+1],a[k][qwe-1])),k=n,op[k]=a[k][qwe+1]>=a[k][qwe+-1]?qwe+1:qwe-1,op[j]=qwe;
	//					}else if(qwe==3){
	//						if(a[k][qwe]-a[k][qwe-1]>=a[j][qwe]&&a[k][qwe]-a[k][qwe-2]>=a[j][qwe]){
	//						 	ans+=(a[j][qwe]-a[k][qwe]+max(a[k][qwe-2],a[k][qwe-1]));
	//							k=n,op[k]=a[k][qwe-2]>=a[k][qwe+-1]?qwe-2:qwe-1;
								
	//							op[j]=qwe;
		//					}
	//						
							
	//					}
						
	//				}
						
	//			}
				
	//		}
	//	}
	//	cout<<q<<endl;
		cout<<ans<<endl;
		memset(op,0,sizeof(op));
		for(int j=1;j<cnt;j++)s[j].b=0,s[j].ha=0,s[j].m=0;
		bm[1]=0,bm[2]=0,bm[3]=0;
	}
	
	
	return 0;
}
