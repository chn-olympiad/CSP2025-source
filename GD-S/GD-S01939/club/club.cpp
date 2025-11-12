#include<bits/stdc++.h>
#define ad(k) (k=-~k)
#define F(i,a,b) for(register int i=a;i<=b;i=-~i)
#define D(i,a,b) for(register int i=a;i>=b;i=~-i)
#define max(a,b) (a>b?a:b)
using namespace std;const int N=1e5+1;
int T,n;struct node{int x,y,z;}a[N];
int i1,i2,i3,ans;
inline bool cmp(node q,node p){
	int maxa=max(q.x,max(q.y,q.z)),maxb=max(p.x,max(p.y,p.z));
	if(maxa>maxb)return 1;
	return 0;
}inline void dfs(int id,int c1,int c2,int c3,int num){
	if(id==n){ans=max(ans,num);return;}
	if(c1<n/2)dfs(id+1,c1+1,c2,c3,num+a[id+1].x);
	if(c2<n/2)dfs(id+1,c1,c2+1,c3,num+a[id+1].y);
	if(c3<n/2)dfs(id+1,c1,c2,c3+1,num+a[id+1].z);
	return;
}int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		F(i,1,n)cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+n+1,cmp);
		ans=i1=i2=i3=0;
//		F(i,1,n)cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
		if(n>200){
			F(i,1,n){
				if(a[i].x>a[i].y&&a[i].x>a[i].z){
					if(i1<n/2)ans+=a[i].x,i1++;
					else if(a[i].y>a[i].z&&i2<n/2)ans+=a[i].y,i2++;
					else ans+=a[i].z,i3++;
				}else if(a[i].y>a[i].x&&a[i].y>a[i].z){
					if(i2<n/2)ans+=a[i].y,i2++;
					else if(a[i].x>a[i].z&&i1<n/2)ans+=a[i].x,i1++;
					else ans+=a[i].z,i3++;
				}else{
					if(i3<n/2)ans+=a[i].z,i3++;
					else if(a[i].x>a[i].y&&i1<n/2)ans+=a[i].x,i1++;
					else ans+=a[i].y,i2++; 
				}
			}
		}else{
			dfs(1,1,0,0,a[1].x);
			dfs(1,0,1,0,a[1].y);
			dfs(1,0,0,1,a[1].z);
		}cout<<ans<<endl;
	}
	return 0;
}/*
1= RP++ 

3 4
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


*/
