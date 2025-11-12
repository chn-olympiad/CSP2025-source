#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,cnt[3],ans;
struct node{
	int a,b,c;
}
a[100005];
struct node1{
	int val,id;
}
lin[3];
int max3(int x,int y,int z){
	return max(x,max(y,z));
}
int min3(int x,int y,int z){
	return min(x,min(y,z));
}
bool cmp(node x,node y){
	int t1=max3(x.a,x.b,x.c)-min3(x.a,x.b,x.c),t2=max3(y.a,y.b,y.c)-min3(y.a,y.b,y.c);
	if(t1!=t2) return t1>t2;
	return max3(x.a,x.b,x.c)>max3(y.a,y.b,y.c);
}
bool cmp1(node1 x,node1 y){
	return x.val>y.val;
}
void dfs(int id,int now){
	if(id>n){
		if(now>ans) ans=now;
		return;
	}
	if(cnt[0]<n/2){
		cnt[0]++;
		dfs(id+1,now+a[id].a);
		cnt[0]--;
	}
	if(cnt[1]<n/2){
		cnt[1]++;
		dfs(id+1,now+a[id].b);
		cnt[1]--;
	}
	if(cnt[2]<n/2){
		cnt[2]++;
		dfs(id+1,now+a[id].c);
		cnt[2]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt[0]=cnt[1]=cnt[2]=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		if(n<=10){
			dfs(1,0);
			cout<<ans<<endl;
			continue;
		}
		
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			memset(lin,0,sizeof(lin));
			lin[0].val=a[i].a;lin[0].id=0;
			lin[1].val=a[i].b;lin[1].id=1;
			lin[2].val=a[i].c;lin[2].id=2;
			sort(lin,lin+3,cmp1);
			for(int j=0;j<=2;j++){
				if(cnt[lin[j].id]<n/2){
					cnt[lin[j].id]++;
					ans+=lin[j].val;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
