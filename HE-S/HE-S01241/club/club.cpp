#include <bits/stdc++.h>
using namespace std;
long long n,t,cnt,ans,f,f1;
struct node{
	long long x,y,z;
}a[100001];
bool cmp(node a,node b){
    if(a.x!=b.x){
    	return a.x>b.x;
	}else if(a.y!=b.y){
		return a.y>b.y;
	}else{
		return a.z>b.z;
	}
}
void dfs(int x,int w,int v,int y){
	if(x==n+1){
		if(ans<cnt){
			ans=cnt;
		}
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&w<n/2&&a[i].x!=0){
			cnt+=a[x].x;
			dfs(x+1,w+1,v,y);
			cnt-=a[x].x;	
		}else if(i==2&&v<n/2&&a[i].y!=0){
			cnt+=a[x].y;
			dfs(x+1,w,v+1,y);
			cnt-=a[x].y;	
		}else if(y<n/2&&a[i].z!=0){
			cnt+=a[x].z;
			dfs(x+1,w,v,y+1);
			cnt-=a[x].z;	
		}else if(a[i].x==0&&a[i].y==0&&a[i].z==0){
			dfs(x+1,w,v,y);
		}
		
	}
}
void dfs1(int x,int w,int v){
	if(x==n+1){
		if(ans<cnt){
			ans=cnt;
		}
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&w<n/2&&a[i].x!=0){
			cnt+=a[x].x;
			dfs1(x+1,w+1,v);
			cnt-=a[x].x;	
		}else if(i==2&&v<n/2&&a[i].y!=0){
			cnt+=a[x].y;
			dfs1(x+1,w,v+1);
			cnt-=a[x].y;	
		}else if(a[i].x==0&&a[i].y==0&&a[i].z==0){
			dfs1(x+1,w,v);
		}
		
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,cnt=0,f=0,f1=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0){
				f=1;
			}
			if(a[i].z!=0){
				f1=1;
			}
		}
		sort(a+1,a+n+1,cmp);
		if(f==0){
			for(int i=1;i<=n/2;i++){
				cnt+=a[i].x;
			}
			printf("%d",cnt);
			cout<<endl;
		}else if(f1==0){
			dfs1(1,0,0);
		}else{
			dfs(1,0,0,0);
			printf("%d",ans);
			cout<<endl;	
		}
		
	}
	
	return 0;
}
