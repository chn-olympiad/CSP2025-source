#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5; 
int t,n;
struct node{
	int x,y,z;
}a[MAXN],u[MAXN],v[MAXN],w[MAXN];
inline bool cmp1(node x,node y){
	return max(x.y,x.z)-x.x>max(y.y,y.z)-y.x;
}
inline bool cmp2(node x,node y){
	return max(x.x,x.z)-x.y>max(y.x,y.z)-y.y;
}
inline bool cmp3(node x,node y){
	return max(x.x,x.y)-x.z>max(y.x,y.y)-y.z;
}
inline bool cmp4(node x,node y){
	return x.z-x.y>y.z-y.y;
}
inline bool cmp5(node x,node y){
	return x.y-x.z>y.y-y.z;
}
inline bool cmp6(node x,node y){
	return x.z-x.x>y.z-y.x;
}
inline bool cmp7(node x,node y){
	return x.x-x.z>y.x-y.z;
}
inline bool cmp8(node x,node y){
	return x.y-x.x>y.y-y.x;
}
inline bool cmp9(node x,node y){
	return x.x-x.y>y.x-y.y;
}
inline void solve(){
	memset(u,0,sizeof(u));
	memset(v,0,sizeof(v));
	memset(w,0,sizeof(w));
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i].x>>a[i].y>>a[i].z;
	int cnt1=0,cnt2=0,cnt3=0,sum=0;
	for(int i=1;i<=n;++i){
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z)u[++cnt1]=a[i];
		else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)v[++cnt2]=a[i];
		else w[++cnt3]=a[i];
	}
	for(int i=1;i<=n;++i)sum+=max(max(a[i].x,a[i].y),a[i].z);
	if(cnt1>n/2){
		sort(u+1,u+cnt1+1,cmp1);
		for(int i=1;cnt1>n/2;++i){
			cnt1--;
			sum-=u[i].x;
			if(u[i].y>u[i].z){
				++cnt2;
				sum+=u[i].y;
				v[++cnt2]=u[i];
			}else{
				++cnt3;
				sum+=u[i].z;
				w[++cnt3]=u[i];
			}
		}
		if(cnt2>n/2){
			sort(v+1,v+cnt2+1,cmp4);
			for(int i=1;cnt2>n/2;++i){
				--cnt2;
				++cnt3;
				sum+=v[i].z-v[i].y;
			}
		}else if(cnt3>n/2){
			sort(w+1,w+cnt3+1,cmp5);
			for(int i=1;cnt3>n/2;++i){
				--cnt3;
				++cnt2;
				sum+=w[i].y-w[i].z;
			}
		}
	}else if(cnt2>n/2){
		sort(v+1,v+cnt2+1,cmp2);
		for(int i=1;cnt2>n/2;++i){
			--cnt2;
			sum-=v[i].y;
			if(v[i].x>v[i].z){
				++cnt1;
				sum+=v[i].x;
				u[++cnt1]=v[i];
			}else{
				++cnt3;
				sum+=v[i].z;
				w[++cnt3]=v[i];
			}
		}
		if(cnt1>n/2){
			sort(u+1,u+cnt1+1,cmp6);
			for(int i=1;cnt1>n/2;++i){
				--cnt1;
				++cnt3;
				sum+=u[i].z-u[i].x;
			}
		}else if(cnt3>n/2){
			sort(w+1,w+cnt3+1,cmp7);
			for(int i=1;cnt3>n/2;++i){
				--cnt3;
				++cnt1;
				sum+=w[i].x-w[i].z;
			}
		}
	}else if(cnt3>n/2){
		sort(w+1,w+cnt3+1,cmp3);
		for(int i=1;cnt3>n/2;++i){
			--cnt3;
			sum-=w[i].z;
			if(w[i].x>w[i].y){
				++cnt1;
				sum+=w[i].x;
				u[++cnt1]=w[i];
			}else{
				++cnt2;
				sum+=w[i].y;
				v[++cnt2]=w[i];
			}
		}
		if(cnt1>n/2){
			sort(u+1,u+cnt1+1,cmp8);
			for(int i=1;cnt1>n/2;++i){
				--cnt1;
				++cnt2;
				sum+=u[i].y-u[i].x;
			}
		}else if(cnt2>n/2){
			sort(v+1,v+cnt2+1,cmp9);
			for(int i=1;cnt2>n/2;++i){
				--cnt2;
				++cnt1;
				sum+=v[i].x-v[i].y;
			}
		}
	}
	cout<<sum<<"\n";
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)solve();
	return 0;
}
