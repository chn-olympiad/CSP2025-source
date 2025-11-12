#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int id;
	int cb;
	int c;
};
node smax[100009];
node smid[100009];
node smin[100009];
bool vis[100009];
bool cmp(node x,node y){
	if(x.c!=y.c){
		return x.c>y.c;
	}
	else{
		return x.a>y.a;
	}
}
bool cmpp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		int c1=0;
		int c2=0;
		int c3=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			if(a1>=a2&&a2>=a3){
				node x1,x2,x3;
				x1.a=a1;
				x1.c=a1-a2;
				x1.cb=1;
				x1.id=i;
				x2.a=a2;
				x2.c=a2-a3;
				x2.cb=2;
				x2.id=i;
				x3.a=a3;
				x3.c=a3-a3;
				x3.cb=3;
				x3.id=i;
				smax[i]=x1;
				smid[i]=x2;
				smin[i]=x3;
			}
			else if(a1>=a3&&a3>=a2){
				node x1,x2,x3;
				x1.a=a1;
				x1.c=a1-a3;
				x1.cb=1;
				x1.id=i;
				x2.a=a2;
				x2.c=a2-a2;
				x2.cb=2;
				x2.id=i;
				x3.a=a3;
				x3.c=a3-a2;
				x3.cb=3;
				x3.id=i;
				smax[i]=x1;
				smid[i]=x3;
				smin[i]=x2;
			}
			else if(a2>=a1&&a1>=a3){
				node x1,x2,x3;
				x1.a=a1;
				x1.c=a1-a3;
				x1.cb=1;
				x1.id=i;
				x2.a=a2;
				x2.c=a2-a1;
				x2.cb=2;
				x2.id=i;
				x3.a=a3;
				x3.c=a3-a3;
				x3.cb=3;
				x3.id=i;
				smax[i]=x2;
				smid[i]=x1;
				smin[i]=x3;
			}
			else if(a2>=a3&&a3>=a1){
				node x1,x2,x3;
				x1.a=a1;
				x1.c=a1-a1;
				x1.cb=1;
				x1.id=i;
				x2.a=a2;
				x2.c=a2-a3;
				x2.cb=2;
				x2.id=i;
				x3.a=a3;
				x3.c=a3-a1;
				x3.cb=3;
				x3.id=i;
				smax[i]=x2;
				smid[i]=x3;
				smin[i]=x1;
			}
			else if(a3>=a1&&a1>=a2){
				node x1,x2,x3;
				x1.a=a1;
				x1.c=a1-a2;
				x1.cb=1;
				x1.id=i;
				x2.a=a2;
				x2.c=a2-a2;
				x2.cb=2;
				x2.id=i;
				x3.a=a3;
				x3.c=a3-a1;
				x3.cb=3;
				x3.id=i;
				smax[i]=x3;
				smid[i]=x1;
				smin[i]=x2;
			}
			else if(a3>=a2&&a2>=a1){
				node x1,x2,x3;
				x1.a=a1;
				x1.c=a1-a1;
				x1.cb=1;
				x1.id=i;
				x2.a=a2;
				x2.c=a2-a1;
				x2.cb=2;
				x2.id=i;
				x3.a=a3;
				x3.c=a3-a2;
				x3.cb=3;
				x3.id=i;
				smax[i]=x3;
				smid[i]=x2;
				smin[i]=x1;
			}
		}
		sort(smax+1,smax+1+n,cmp);
		sort(smid+1,smid+1+n,cmp);
		sort(smin+1,smin+1+n,cmpp);	
		queue <node> q;
		for(int i=1;i<=n;i++){
			q.push(smax[i]);
		}
		for(int i=1;i<=n;i++){
			q.push(smid[i]);
		}
		for(int i=1;i<=n;i++){
			q.push(smin[i]);
		}
		int k=n/2;
		long long ans=0;
		long long nn=0;
		for(int i=1;nn<n;i++){
			node x=q.front();
			q.pop();
			if(x.cb==1){
				if(vis[x.id]==0&&c1<k){
					ans+=x.a;
					vis[x.id]=1;
					c1++;
					nn++;
				}
			}
			else if(x.cb==2){
				if(vis[x.id]==0&&c2<k){
					ans+=x.a;
					vis[x.id]=1;
					c2++;
					nn++;
				}
			}
			else{
				if(vis[x.id]==0&&c3<k){
					ans+=x.a;
					vis[x.id]=1;
					c3++;	
					nn++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 