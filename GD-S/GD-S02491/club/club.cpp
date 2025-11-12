#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}a[100001],b[100001],c[100001];
bool cmp(node p,node q){
	return p.x>q.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0,bz[100005],xx=0;
		memset(bz,0,sizeof(bz));
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>b[i].x>>c[i].x;
			a[i].y=i,b[i].y=i,c[i].y=i;
			if(b[i].x!=0 or c[i].x!=0) xx=1;
		}
		if(n==2){
			cout<<max(a[1].x+b[2].x,max(a[1].x+c[2].x,max(b[1].x+a[2].x,max(b[1].x+c[2].x,max(c[1].x+a[2].x,c[1].x+b[2].x)))))<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		if(!xx){
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			cout<<ans<<endl;
			continue;
		}
		cout<<a[1].x*n/2<<endl;
	} 
} //Ren5Jie4Di4Ling5%
