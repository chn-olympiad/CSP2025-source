#include<bits/stdc++.h>
using namespace std;

int t,n,ans,sum[3];
int xs1[100005],xs2[100005],xs3[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int u,v,w,p;
	while(t--){
		ans=0;
		memset(sum,0,sizeof(sum));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>u>>v>>w;
			if(u>=v && u>=w)
				xs1[++sum[0]]=u-max(v,w);	
			else if(v>=u && v>=w)
				xs2[++sum[1]]=v-max(u,w);
			else
				xs3[++sum[2]]=w-max(u,v);
			ans+=max(u,max(v,w));
		}
		if(sum[0]>n/2){
			sort(xs1+1,xs1+sum[0]+1);
			for(int i=1;i<=sum[0]-n/2;i++)
				ans-=xs1[i];
		}
		else if(sum[1]>n/2){
			sort(xs2+1,xs2+sum[1]+1);
			for(int i=1;i<=sum[1]-n/2;i++)
				ans-=xs2[i];
		}
		else{
			sort(xs3+1,xs3+sum[2]+1);
			for(int i=1;i<=sum[2]-n/2;i++)
				ans-=xs3[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
