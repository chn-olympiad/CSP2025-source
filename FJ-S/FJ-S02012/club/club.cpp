/*
打成这样没事，就当成献祭文化课了/qiang
AFOed---luogu658995
中考加油
*/
#include<bits/stdc++.h>
using namespace std;
int t,n,num[3]={0};
struct node{
	int a,b,c;
}sum[100010];
bool cmp(node x,node y){
	int l[3],r[3];
	l[1]=x.a,l[2]=x.b,l[3]=x.c;
	r[1]=y.a,r[2]=y.b,r[3]=y.c;
	sort(l+1,l+1+3);
	sort(r+1,r+1+3);
	if(l[3]-l[2]==r[3]-r[2]){
		if(l[3]-l[1]==r[3]-r[1])
		return l[2]-l[1]>r[2]-r[1];
		else
		return l[3]-l[1]>r[3]-r[1];
	}
	else{
		return l[3]-l[2]>r[3]-r[2];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans=0;
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&sum[i].a,&sum[i].b,&sum[i].c);
		}
			
		sort(sum+1,sum+1+n,cmp);
		for(int i=1;i<=n;i++){
		
			if(sum[i].a>sum[i].b&&sum[i].a>sum[i].c){
				
				if(num[1]+1<=n/2){
				ans+=sum[i].a,num[1]++;}
				else{
					
					if(sum[i].b>sum[i].c){
						if(num[2]+1<=n/2)ans+=sum[i].b,num[2]++;
						else ans+=sum[i].c,num[3]++;
					}
					else{
						if(num[3]+1<=n/2)ans+=sum[i].c,num[3]++;
						else ans+=sum[i].b,num[2]++;
					}
				}
				
			}
			if(sum[i].b>sum[i].a&&sum[i].b>sum[i].c){
				//cout<<i<<"*"<<endl;cout<<num[1]<<" "<<num[2]<<" "<<num[3]<<" "<<ans<<endl;
				if(num[2]+1<=n/2){
					ans+=sum[i].b,num[2]++;}
				else{
					//cout<<"c"<<endl;
					if(sum[i].a>sum[i].c){
						if(num[1]+1<=n/2)ans+=sum[i].a,num[1]++;
						else ans+=sum[i].c,num[3]++;
					}
					else{
						if(num[3]+1<=n/2)ans+=sum[i].c,num[3]++;
						else ans+=sum[i].a,num[1]++;
					}
				}
			}
			if(sum[i].c>sum[i].b&&sum[i].c>sum[i].a){
				//cout<<i<<"**"<<endl;
				if(num[3]+1<=n/2){
					ans+=sum[i].c,num[3]++;}
				else{
					//cout<<"c"<<endl;
					if(sum[i].a>sum[i].b){
						if(num[1]+1<=n/2)ans+=sum[i].a,num[1]++;
						else ans+=sum[i].b,num[2]++;
					}
					else{
						if(num[2]+1<=n/2)ans+=sum[i].b,num[2]++;
						else ans+=sum[i].a,num[1]++;
					}
				}
			}
			//cout<<ans<<endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}
