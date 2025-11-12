#include<bits/stdc++.h>
using namespace std;
int t,n,sum,vis[4];
int ans[6];
struct node{
	int a,b,c;
}d[100010];
bool cmp0(node x,node y){
	return x.a>y.a;
}bool cmp1(node x,node y){
	return x.b>y.b;
}bool cmp2(node x,node y){
	return x.c>y.c;
}bool cmp3(node x,node y){
	return x.a<y.a;
}bool cmp4(node x,node y){
	return x.b<y.b;
}bool cmp5(node x,node y){
	return x.c<y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
		}sort(d+1,d+n+1,cmp0);
		for(int i=1;i<=n;i++){
			if(d[i].a>=d[i].b&&d[i].a>=d[i].c&&vis[0]<n/2){
				vis[0]++;
				ans[0]+=d[i].a;
			}else if(d[i].b>=d[i].a&&d[i].b>=d[i].c&&vis[1]<n/2){
				vis[1]++;
				ans[0]+=d[i].b;
			}else if(d[i].c>=d[i].b&&d[i].c>=d[i].a&&vis[2]<n/2){
				vis[2]++;
				ans[0]+=d[i].c;
			}else{
				if(d[i].a>=d[i].b&&vis[0]<n/2){
					vis[0]++;
					ans[0]+=d[i].a;
				}else if(d[i].b>=d[i].c&&vis[1]<n/2){
					vis[1]++;
					ans[0]+=d[i].b;
				}else if(d[i].b>=d[i].a&&vis[1]<n/2){
					vis[1]++;
					ans[0]+=d[i].b;
				}else if(d[i].a>=d[i].c&&vis[0]<n/2){
					vis[0]++;
					ans[0]+=d[i].a;
				}else if(d[i].c>=d[i].a&&vis[2]<n/2){
					vis[2]++;
					ans[0]+=d[i].c;
				}else if(d[i].c>=d[i].b&&vis[2]<n/2){
					vis[2]++;
					ans[0]+=d[i].c;
				}
			}
		}vis[0]=0;
		vis[1]=0;
		vis[2]=0;
		sort(d+1,d+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(d[i].a>=d[i].b&&d[i].a>=d[i].c&&vis[0]<n/2){
				vis[0]++;
				ans[1]+=d[i].a;
			}else if(d[i].b>=d[i].a&&d[i].b>=d[i].c&&vis[1]<n/2){
				vis[1]++;
				ans[1]+=d[i].b;
			}else if(d[i].c>=d[i].b&&d[i].c>=d[i].a&&vis[2]<n/2){
				vis[2]++;
				ans[1]+=d[i].c;
			}else{
				if(d[i].a>=d[i].b&&vis[0]<n/2){
					vis[0]++;
					ans[1]+=d[i].a;
				}else if(d[i].b>=d[i].c&&vis[1]<n/2){
					vis[1]++;
					ans[1]+=d[i].b;
				}else if(d[i].b>=d[i].a&&vis[1]<n/2){
					vis[1]++;
					ans[1]+=d[i].b;
				}else if(d[i].a>=d[i].c&&vis[0]<n/2){
					vis[0]++;
					ans[1]+=d[i].a;
				}else if(d[i].c>=d[i].a&&vis[2]<n/2){
					vis[2]++;
					ans[1]+=d[i].c;
				}else if(d[i].c>=d[i].b&&vis[2]<n/2){
					vis[2]++;
					ans[1]+=d[i].c;
				}
			}
		}vis[0]=0;
		vis[1]=0;
		vis[2]=0;
		sort(d+1,d+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(d[i].a>=d[i].b&&d[i].a>=d[i].c&&vis[0]<n/2){
				vis[0]++;
				ans[2]+=d[i].a;
			}else if(d[i].b>=d[i].a&&d[i].b>=d[i].c&&vis[1]<n/2){
				vis[1]++;
				ans[2]+=d[i].b;
			}else if(d[i].c>=d[i].b&&d[i].c>=d[i].a&&vis[2]<n/2){
				vis[2]++;
				ans[2]+=d[i].c;
			}else{
				if(d[i].a>=d[i].b&&vis[0]<n/2){
					vis[0]++;
					ans[2]+=d[i].a;
				}else if(d[i].b>=d[i].c&&vis[1]<n/2){
					vis[1]++;
					ans[2]+=d[i].b;
				}else if(d[i].b>=d[i].a&&vis[1]<n/2){
					vis[1]++;
					ans[2]+=d[i].b;
				}else if(d[i].a>=d[i].c&&vis[0]<n/2){
					vis[0]++;
					ans[2]+=d[i].a;
				}else if(d[i].c>=d[i].a&&vis[2]<n/2){
					vis[2]++;
					ans[2]+=d[i].c;
				}else if(d[i].c>=d[i].b&&vis[2]<n/2){
					vis[2]++;
					ans[2]+=d[i].c;
				}
			}
		}vis[0]=0;
		vis[1]=0;
		vis[2]=0;
		sort(d+1,d+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(d[i].a>=d[i].b&&d[i].a>=d[i].c&&vis[0]<n/2){
				vis[0]++;
				ans[3]+=d[i].a;
			}else if(d[i].b>=d[i].a&&d[i].b>=d[i].c&&vis[1]<n/2){
				vis[1]++;
				ans[3]+=d[i].b;
			}else if(d[i].c>=d[i].b&&d[i].c>=d[i].a&&vis[2]<n/2){
				vis[2]++;
				ans[3]+=d[i].c;
			}else{
				if(d[i].a>=d[i].b&&vis[0]<n/2){
					vis[0]++;
					ans[3]+=d[i].a;
				}else if(d[i].b>=d[i].c&&vis[1]<n/2){
					vis[1]++;
					ans[3]+=d[i].b;
				}else if(d[i].b>=d[i].a&&vis[1]<n/2){
					vis[1]++;
					ans[3]+=d[i].b;
				}else if(d[i].a>=d[i].c&&vis[0]<n/2){
					vis[0]++;
					ans[3]+=d[i].a;
				}else if(d[i].c>=d[i].a&&vis[2]<n/2){
					vis[2]++;
					ans[3]+=d[i].c;
				}else if(d[i].c>=d[i].b&&vis[2]<n/2){
					vis[2]++;
					ans[3]+=d[i].c;
				}
			}
		}vis[0]=0;
		vis[1]=0;
		vis[2]=0;
		sort(d+1,d+n+1,cmp4);
		for(int i=1;i<=n;i++){
			if(d[i].a>=d[i].b&&d[i].a>=d[i].c&&vis[0]<n/2){
				vis[0]++;
				ans[4]+=d[i].a;
			}else if(d[i].b>=d[i].a&&d[i].b>=d[i].c&&vis[1]<n/2){
				vis[1]++;
				ans[4]+=d[i].b;
			}else if(d[i].c>=d[i].b&&d[i].c>=d[i].a&&vis[2]<n/2){
				vis[2]++;
				ans[4]+=d[i].c;
			}else{
				if(d[i].a>=d[i].b&&vis[0]<n/2){
					vis[0]++;
					ans[4]+=d[i].a;
				}else if(d[i].b>=d[i].c&&vis[1]<n/2){
					vis[1]++;
					ans[4]+=d[i].b;
				}else if(d[i].b>=d[i].a&&vis[1]<n/2){
					vis[1]++;
					ans[4]+=d[i].b;
				}else if(d[i].a>=d[i].c&&vis[0]<n/2){
					vis[0]++;
					ans[4]+=d[i].a;
				}else if(d[i].c>=d[i].a&&vis[2]<n/2){
					vis[2]++;
					ans[4]+=d[i].c;
				}else if(d[i].c>=d[i].b&&vis[2]<n/2){
					vis[2]++;
					ans[4]+=d[i].c;
				}
			}
		}vis[0]=0;
		vis[1]=0;
		vis[2]=0;
		sort(d+1,d+n+1,cmp5);
		for(int i=1;i<=n;i++){
			if(d[i].a>=d[i].b&&d[i].a>=d[i].c&&vis[0]<n/2){
				vis[0]++;
				ans[5]+=d[i].a;
			}else if(d[i].b>=d[i].a&&d[i].b>=d[i].c&&vis[1]<n/2){
				vis[1]++;
				ans[5]+=d[i].b;
			}else if(d[i].c>=d[i].b&&d[i].c>=d[i].a&&vis[2]<n/2){
				vis[2]++;
				ans[5]+=d[i].c;
			}else{
				if(d[i].a>=d[i].b&&vis[0]<n/2){
					vis[0]++;
					ans[5]+=d[i].a;
				}else if(d[i].b>=d[i].c&&vis[1]<n/2){
					vis[1]++;
					ans[5]+=d[i].b;
				}else if(d[i].b>=d[i].a&&vis[1]<n/2){
					vis[1]++;
					ans[5]+=d[i].b;
				}else if(d[i].a>=d[i].c&&vis[0]<n/2){
					vis[0]++;
					ans[5]+=d[i].a;
				}else if(d[i].c>=d[i].a&&vis[2]<n/2){
					vis[2]++;
					ans[5]+=d[i].c;
				}else if(d[i].c>=d[i].b&&vis[2]<n/2){
					vis[2]++;
					ans[5]+=d[i].c;
				}
			}
		}vis[0]=0;
		vis[1]=0;
		vis[2]=0;
		cout<<max(ans[0],max(ans[1],max(ans[2],max(ans[3],max(ans[5],ans[4])))))<<endl;
		ans[0]=0;
		ans[1]=0;
		ans[2]=0;
		ans[3]=0;
		ans[4]=0;
		ans[5]=0;
	}
	return 0;
}
