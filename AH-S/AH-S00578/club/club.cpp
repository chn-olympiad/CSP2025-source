#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][4];
int sum0[100005],sum1[100005],sum2[100005];
long long ans=0;
bool cmp0(int i,int j){
    return a[i][0]-a[i][3]<a[j][0]-a[j][3];
}
bool cmp1(int i,int j){
    return a[i][1]-a[i][3]<a[j][1]-a[j][3];
}
bool cmp2(int i,int j){
    return a[i][2]-a[i][3]<a[j][2]-a[j][3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
        memset(sum0,0,sizeof(sum0));
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
        memset(a,0,sizeof(a));
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
        for(int i=1;i<=n;i++){
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
                sum0[0]++;
                sum0[sum0[0]]=i;
                a[i][3]=max(a[i][1],a[i][2]);
                ans+=a[i][0];
            }
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
                sum1[0]++;
                sum1[sum1[0]]=i;
                a[i][3]=max(a[i][0],a[i][2]);
                ans+=a[i][1];
            }
            else{
                sum2[0]++;
                sum2[sum2[0]]=i;
                a[i][3]=max(a[i][1],a[i][0]);
                ans+=a[i][2];
            }
        }
        if(sum0[0]>n/2){
            int t=sum0[0]-n/2;
            sort(sum0+1,sum0+sum0[0]+1,cmp0);
            for(int i=1;i<=t;i++)
                ans-=a[sum0[i]][0]-a[sum0[i]][3];
        }
        else if(sum1[0]>n/2){
            int t=sum1[0]-n/2;
            sort(sum1+1,sum1+sum1[0]+1,cmp1);
            for(int i=1;i<=t;i++)
                ans-=a[sum1[i]][1]-a[sum1[i]][3];
        }
        else if(sum2[0]>n/2){
            int t=sum2[0]-n/2;
            sort(sum2+1,sum2+sum2[0]+1,cmp2);
            for(int i=1;i<=t;i++)
                ans-=a[sum2[i]][2]-a[sum2[i]][3];
        }
        printf("%lld \n",ans);
	}
	return 0;
}
/*                    */
