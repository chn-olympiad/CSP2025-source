#include<bits/stdc++.h>
using namespace std;
//请欣赏：超长史山代码 
struct node{
	int x,y,z;
}a[500005];
bool cmp(node t1,node t2){
	int q1[]={t1.x,t1.y,t1.z};
	int q2[]={t2.x,t2.y,t2.z};
	sort(q1,q1+3),sort(q2,q2+3);
	if(q1[2]!=q2[2])return q1[2]>q2[2];
	else if(q1[1]!=q2[1])return q1[1]>q2[1];
	else return q1[0]>q2[0];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
    cin>>T;
	for(int i=1;i<=T;i++){
		memset(a,0,sizeof(a));
		long long ans=0;
		int n,now=1,cntx=0,cnty=0,cntz=0;
		bool fx=0,fy=0,fz=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a[j].x,&a[j].y,&a[j].z);
		}
		stable_sort(a+1,a+n+1,cmp);
		for(int j=1;j<=n;j++){
				int t=max(a[j].x,max(a[j].y,a[j].z));
				//cout<<t<<endl;
				//cout<<fx<<' '<<fy<<' '<<fz<<endl;
				//cout<<cntx<<' '<<cnty<<' '<<cntz<<endl;
				if(t==a[j].x){
					if(fx==1){
					    int w[]={a[j].x,a[j].y,a[j].z};
				        sort(w,w+3);
				        ans+=w[1];
				        /*if(w[1]==a[j].x)cntx++;
				        if(w[1]==a[j].y)cnty++;
				        if(w[1]==a[j].z)cntz++;*/
					}else{
						cntx++;
					    if(cntx>=n/2){
					        fx=1;	
						}
					    ans+=t;
					}
				}else if(t==a[j].y){
					if(fy==1){
					    int w[]={a[j].x,a[j].y,a[j].z};
				        sort(w,w+3);
				        ans+=w[1];
				        /*if(w[1]==a[j].x)cntx++;
				        if(w[1]==a[j].y)cnty++;
				        if(w[1]==a[j].z)cntz++;*/
					}else{
						cnty++;
					    if(cnty>=n/2){
					    	fy=1;
						}
					    ans+=t;
					}
				}else if(t==a[j].z){
					if(fz==1){
					    int w[]={a[j].x,a[j].y,a[j].z};
				        sort(w,w+3);
				        ans+=w[1];
				        /*if(w[1]==a[j].x)cntx++;
				        if(w[1]==a[j].y)cnty++;
				        if(w[1]==a[j].z)cntz++;*/
					}else{
						cntz++;
					    if(cntz>=n/2)fz=1;
					    ans+=t;
					}
				}
			}
		cout<<ans<<endl;
	}
	return 0;
} 
