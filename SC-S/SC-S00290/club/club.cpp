#include<bits/stdc++.h>
using namespace std;
int T;
const int N=1e5+9;
int n;
struct node{
	int x,y,z;
	friend bool operator<(node x,node y){
		return max(x.x,max(x.y,x.z))>max(y.x,max(y.y,y.z));
	}
}a[N];
int sumx,sumy,sumz,ans;
int cntx;
priority_queue<int>q;
inline void read(int &n){
	n=0;
	char c=getchar();
	while(c<=32)c=getchar();
	while(c>='0'&&c<='9')n=n*10+c-'0',c=getchar();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		sumx=sumy=sumz=ans=cntx=0;
		while(!q.empty())q.pop();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			read(a[i].x),read(a[i].y),read(a[i].z);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i].x==max(a[i].x,max(a[i].y,a[i].z)))
				++sumx;
			else if(a[i].y==max(a[i].x,max(a[i].y,a[i].z)))
				++sumy;
			else ++sumz;
		}
		if(sumy>n/2)for(int i=1;i<=n;i++)swap(a[i].x,a[i].y);
		if(sumz>n/2)for(int i=1;i<=n;i++)swap(a[i].x,a[i].z);
		for(int i=1;i<=n;i++){
			if(a[i].x==max(a[i].x,max(a[i].y,a[i].z))){
				if(cntx==n/2){
					if(q.top()+a[i].x>max(a[i].y,a[i].z))
						q.push(-a[i].x+max(a[i].y,a[i].z)),ans+=q.top()+a[i].x,q.pop();
					else ans+=max(a[i].y,a[i].z);
				}else{
					++cntx,q.push(-a[i].x+max(a[i].y,a[i].z));
					ans+=a[i].x;
				}
			}else{
				ans+=max(a[i].y,a[i].z);
			}
		}
		printf("%d\n",ans);
	}
}