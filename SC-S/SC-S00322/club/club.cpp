#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e5+10;
struct neww{
	ll x,y,z,num;
} a[maxn],b[maxn],c[maxn];
ll T,n,sum_1,sum_2,sum_3,ans;
bool fx,fy,fz,vis[maxn];
inline void jia_a(int i){
	ans+=a[i].x;
	sum_1++;
	vis[a[i].num]=1;
}
inline void jia_b(int i){
	ans+=b[i].y;
	sum_2++;
	vis[b[i].num]=1;
}
inline void jia_c(int i){
	ans+=c[i].z;
	sum_3++;
	vis[c[i].num]=1;
}
bool cmp_a(neww nick,neww jack){
	return nick.x>=jack.x;
}
bool cmp_b(neww jensen,neww kevin){
	return jensen.y>=kevin.y;
}
bool cmp_c(neww aria,neww king){
	return aria.z>=king.z;
}
inline void work1(int i){
	if(a[i].x>b[i].y && a[i].x>c[i].z) jia_a(i);
	else if(b[i].y>a[i].x && b[i].y>c[i].z) jia_b(i);
	else jia_c(i);
}
inline void work2(int i){
	if(a[i].x>b[i].y){jia_a(i);}else{jia_b(i);}
	if(!fz) jia_c(i);
}
inline void work3(int i){
	if(a[i].x>c[i].z){jia_a(i);}else{jia_c(i);}
	if(!fy) jia_b(i);
}
inline void work4(int i){
	if(b[i].y>c[i].z){jia_b(i);}else{jia_c(i);}
	if(!fx) jia_a(i);
}
inline void check(){
	if(sum_1==(n/2)) fx=1;
	if(sum_2==(n/2)) fy=1;
	if(sum_3==(n/2)) fz=1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			b[i].x=a[i].x,b[i].y=a[i].y,b[i].z=a[i].z;
			c[i].x=a[i].x,c[i].y=a[i].y,c[i].z=a[i].z;
			a[i].num=b[i].num=c[i].num=i;
		}
		//输入 
		sort(a+1,a+n+1,cmp_a),sort(b+1,b+n+1,cmp_b),sort(c+1,c+n+1,cmp_c);
		memset(vis,0,sizeof(vis));
		sum_1=sum_2=sum_3=0,ans=0,fx=fy=fz=0;
		//贪心 
		for(int i=1;i<=n;i++){
			check();
			if(a[i].num==b[i].num && a[i].num==c[i].num && !fx && !fy && !fz && !vis[a[i].num]){
				work1(i);
				//cout<<"1 "<<ans<<endl;
				continue; 
			}
			//三人成行 
			if(a[i].num==b[i].num && !fx && !fy && !vis[a[i].num]){
				work2(i);	//cout<<"2 "<<ans<<endl;
				continue;
			}else if(a[i].num==c[i].num && !fx && !fz && !vis[a[i].num]){
				work3(i);	//cout<<"3 "<<ans<<endl;
				continue;
			}else if(c[i].num==b[i].num && !fy && !fz  && !vis[b[i].num]){
				work4(i); 	//cout<<"4 "<<ans<<endl;
				continue;
			}
			//双人成行 
			if(!fx && !vis[a[i].num]) jia_a(i);
			if(!fy && !vis[b[i].num]) jia_b(i);
			if(!fz && !vis[c[i].num]) jia_c(i);
			//单人成行 
		}
		cout<<ans<<endl;
	}
	return 0;
} 