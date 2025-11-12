#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
typedef long long ll;
ll T,n,ans=-1,ans1,sum;
ll a1,b1,c1;
ll vis[N];
struct node{
	ll x,id;
}a[N],b[N],c[N];
struct node1{
	int cnt,a1,b1,c1;
	ll num;
}v[7*N];
bool cmp1(node x,node y){
	return x.x>y.x;
}
inline ll read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}

void bfs(){
	int h=0,t=1;
	v[t].cnt=v[t].a1=v[t].b1=v[t].c1=v[t].num=0;
	while(h<=t&&v[h].cnt!=n){
		h++;
//		for(int i=v[h].cnt+1;i<=n;i++){
//			if(!vis[i]){
//				vis[i]=1;
				if(v[h].a1<n/2&&a[v[h].cnt+1].x>=vis[v[h].cnt+1]/3*2){
					t++;
					
					v[t].a1=v[h].a1+1;
					v[t].b1=v[h].b1;
					v[t].c1=v[h].c1;
					v[t].num=v[h].num+a[v[h].cnt+1].x;
					v[t].cnt=v[h].cnt+1;
//					cout<<h<<" "<<t<<" a add "<<" "<<v[t].cnt<<" "<<v[t].num<<'\n';
					if(v[t].cnt==n) ans=max(ans,v[t].num);
				} 
				if(v[h].b1<n/2&&b[v[h].cnt+1].x>=vis[v[h].cnt+1]/3*2){
					
					t++;
					v[t].a1=v[h].a1;
					
					v[t].c1=v[h].c1;
					v[t].b1=v[h].b1+1;
					v[t].num=v[h].num+b[v[h].cnt+1].x;
					v[t].cnt=v[h].cnt+1;
//					cout<<h<<" "<<t<<" b add "<<" "<<v[t].cnt<<" "<<v[t].num<<'\n';
					if(v[t].cnt==n) ans=max(ans,v[t].num);
				} 
				if(v[h].c1<n/2&&c[v[h].cnt+1].x>=vis[v[h].cnt+1]/3*2){
					
					t++;
					
					v[t].b1=v[h].b1;
					v[t].a1=v[h].a1;
					v[t].c1=v[h].c1+1;
					v[t].num=v[h].num+c[v[h].cnt+1].x;
					v[t].cnt=v[h].cnt+1;
//					cout<<h<<" "<<t<<" c add "<<" "<<v[t].cnt<<" "<<v[t].num<<'\n';
					if(v[t].cnt==n) ans=max(ans,v[t].num);
				} 
//				break;
//			}
			
//		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	for(int z=1;z<=T;z++){
		n=read();
		
		for(int i=1;i<=n;i++){
			a[i].id=b[i].id=c[i].id=i;
			a[i].x=read();b[i].x=read();c[i].x=read();
			vis[i]=max(a[i].x,b[i].x);
			vis[i]=max(vis[i],c[i].x);
		}
//		sort(a+1,a+1+n,cmp1);
//		sort(b+1,b+1+n,cmp1);
//		sort(c+1,c+1+n,cmp1);
//		for(int i=1;i<=n;i++){
//			if(!vis[a[i].id]&&a1<=n/2-1){
//				ans1+=a[i].x;
//				vis[a[i].id]=1;
//				a1++;
//				sum++;
//			} 
//			if(!vis[b[i].id]&&b1<=n/2-1){
//				ans1+=b[i].x;
//				vis[b[i].id]=1;
//				b1++;
//				sum++;
//			} 
//			if(!vis[c[i].id]&&c1<=n/2-1){
//				ans1+=c[i].x;
//				vis[c[i].id]=1;
//				c1++;
//				sum++;
//			}
//			if(sum==n) break; 
//		}
//		for(int i=1;i<=n;i++) vis[i]=0;
//		ans=max(ans1,ans);
//		sum=ans1=a1=b1=c1=0;
//		
//		for(int i=1;i<=n;i++){
//			if(!vis[a[i].id]&&a1<=n/2-1){
//				ans1+=a[i].x;
//				vis[a[i].id]=1;
//				a1++;
//				sum++;
//			} 
//			if(!vis[c[i].id]&&c1<=n/2-1){
//				ans1+=c[i].x;
//				vis[c[i].id]=1;
//				c1++;
//				sum++;
//			} 
//			if(!vis[b[i].id]&&b1<=n/2-1){
//				ans1+=b[i].x;
//				vis[b[i].id]=1;
//				b1++;
//				sum++;
//			} 
//			if(sum==n) break;
//		}
//		ans=max(ans1,ans);
//		sum=ans1=a1=b1=c1=0;
//		for(int i=1;i<=n;i++) vis[i]=0;
//		
//		for(int i=1;i<=n;i++){
//			if(!vis[b[i].id]&&b1<=n/2-1){
//				ans1+=b[i].x;
//				vis[b[i].id]=1;
//				b1++;
//				sum++;
//			} 
//			if(!vis[a[i].id]&&a1<=n/2-1){
//				ans1+=a[i].x;
//				vis[a[i].id]=1;
//				a1++;
//				sum++;
//			}
//			if(!vis[c[i].id]&&c1<=n/2-1){
//				ans1+=c[i].x;
//				vis[c[i].id]=1;
//				c1++;
//				sum++;
//			}
//			if(sum==n) break;
//		}
//		ans=max(ans1,ans);
//		sum=ans1=a1=b1=c1=0;
//		for(int i=1;i<=n;i++) vis[i]=0;
//		
//		for(int i=1;i<=n;i++){
//			if(!vis[b[i].id]&&b1<=n/2-1){
//				ans1+=b[i].x;
//				vis[b[i].id]=1;
//				b1++;
//				sum++;
//			} 
//			if(!vis[c[i].id]&&c1<=n/2-1){
//				ans1+=c[i].x;
//				vis[c[i].id]=1;
//				c1++;
//				sum++;
//			}
//			if(!vis[a[i].id]&&a1<=n/2-1){
//				ans1+=a[i].x;
//				vis[a[i].id]=1;
//				a1++;
//				sum++;
//			}
//			if(sum==n) break;
//		}
//		ans=max(ans1,ans);
//		sum=ans1=a1=b1=c1=0;
//		for(int i=1;i<=n;i++) vis[i]=0;
//		
//		for(int i=1;i<=n;i++){
//			if(!vis[c[i].id]&&c1<=n/2-1){
//				ans1+=c[i].x;
//				vis[c[i].id]=1;
//				c1++;
//				sum++;
//			}
//			if(!vis[b[i].id]&&b1<=n/2-1){
//				ans1+=b[i].x;
//				vis[b[i].id]=1;
//				b1++;
//				sum++;
//			} 
//			if(!vis[a[i].id]&&a1<=n/2-1){
//				ans1+=a[i].x;
//				vis[a[i].id]=1;
//				a1++;
//				sum++;
//			}
//			if(sum==n) break;
//		}
//		ans=max(ans1,ans);
//		sum=ans1=a1=b1=c1=0;
//		for(int i=1;i<=n;i++) vis[i]=0;
//		
//		for(int i=1;i<=n;i++){
//			if(!vis[c[i].id]&&c1<=n/2-1){
//				ans1+=c[i].x;
//				vis[c[i].id]=1;
//				c1++;
//				sum++;
//			}
//			if(!vis[a[i].id]&&a1<=n/2-1){
//				ans1+=a[i].x;
//				vis[a[i].id]=1;
//				a1++;
//				sum++; 
//			}
//			if(!vis[b[i].id]&&b1<=n/2-1){
//				ans1+=b[i].x;
//				vis[b[i].id]=1;
//				b1++;
//				sum++;
//			} 
//			if(sum==n) break;
//			
//		}
//		ans=max(ans1,ans);
//		sum=ans1=a1=b1=c1=0;
//		for(int i=1;i<=n;i++) vis[i]=0;
		
		
		bfs();
//		sum=ans1=a1=b1=c1=0;
//		for(int i=1;i<=n;i++) vis[i]=0;
		
		
		for(int i=1;i<=n;i++) a[i].x=a[i].id=b[i].id=b[i].x=c[i].id=c[i].x=0; 
		cout<<ans<<'\n';
		ans=-1;
	} 
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
30
6090 4971 4101
14495 19657 10011
6294 14948 17496
3266 18897 6963
3129 14412 12639
5331 7102 7590
12533 15635 16270
2339 16892 11211
6980 3113 19980
16859 13322 9404
16742 1573 8946
1285 5253 2697
18072 16412 5595
15870 17311 7711
19194 4644 11192
1306 6558 10317
11128 16814 5947
1603 6202 15251
4014 5797 2498
1557 4235 12431
1561 16149 16433
9399 1760 809
13383 18379 10169
7679 4131 17310
2900 8148 13627
14783 19510 17642
19717 4666 6335
9868 5451 19561
11196 1774 11436
10753 10148 6994

*/
