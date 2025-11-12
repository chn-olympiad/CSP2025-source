#include<bits/stdc++.h>
using namespace std;
int n,t1,t2,t3,l[5],t[10];
long long ans=0;
struct node{
	long long x,y,z,max_cha,ci_cha,min_cha;
}a[100005];
struct node2{
	long long rx,ry,rz,ma_cha;
}b[100005];
bool cmp(node A,node B){
	if(A.ci_cha!=B.ci_cha)return A.max_cha>B.max_cha;
	else if(A.max_cha!=B.max_cha)return A.ci_cha>B.ci_cha;
	else return A.min_cha>B.min_cha;
}
bool cmp2(node2 A,node2 B){
	return A.ma_cha>B.ma_cha;
}
void sort_max_min(int x,int y,int z,int i){
	l[1]=x,l[2]=y,l[3]=z;
	sort(l+1,l+4);
	a[i].max_cha=l[3];
	a[i].ci_cha=l[2];
	a[i].min_cha=l[1];
}
void redo1(int j){
	int k=0;
	for(;j<=n;j++){
		k++;
		b[k].rx=a[j].x;
		b[k].ry=a[j].y;
		b[k].rz=a[j].z;
		b[k].ma_cha=max(a[j].y-a[j].z,a[j].z-a[j].y);
	}
	sort(b+1,b+1+k,cmp2);
	for(int i=1;i<=k;i++){
		if(b[i].ma_cha==b[i].rz-b[i].ry){
		    if(t3!=0){
				t3--;
				ans+=b[i].rz;
			}else{
				for(int end=i;end<=k;end++){
					ans+=b[end].ry;
				}
				return;
			}
		}else{
			if(t2!=0){
				t2--;
				ans+=b[i].ry;
			}else{
				for(int end=i;end<=k;end++){
					ans+=b[end].rz;
				}
				return;
			}
		}
	}
}
void redo2(int j){
	int k=0;
	for(;j<=n;j++){
		k++;
		b[k].rx=a[j].x;
		b[k].ry=a[j].y;
		b[k].rz=a[j].z;
		b[k].ma_cha=max(a[j].x-a[j].z,a[j].z-a[j].x);
	}
	sort(b+1,b+1+k,cmp2);
	for(int i=1;i<=k;i++){
		if(b[i].ma_cha==b[i].rx-b[i].rz){
		    if(t1!=0){
				t1--;
				ans+=b[i].rx;
			}else{
				for(int end=i;end<=k;end++){
					ans+=b[end].rz;
				}
				return;
			}
		}else{
			if(t3!=0){
				t3--;
				ans+=b[i].rz;
			}else{
				for(int end=i;end<=k;end++){
					ans+=b[end].rx;
				}
				return;
			}
		}
	}
}
void redo3(int j){
	int k=0;
	for(;j<=n;j++){
		k++;
		b[k].rx=a[j].x;
		b[k].ry=a[j].y;
		b[k].rz=a[j].z;
		b[k].ma_cha=max(a[j].y-a[j].x,a[j].x-a[j].y);
	}
	sort(b+1,b+1+k,cmp2);
	for(int i=1;i<=k;i++){
		if(b[i].ma_cha==b[i].rx-b[i].ry){
		    if(t1!=0){
				t1--;
				ans+=b[i].rx;
			}else{
				for(int end=i;end<=k;end++){
					ans+=b[end].ry;
				}
				return;
			}
		}else{
			if(t2!=0){
				t2--;
				ans+=b[i].ry;
			}else{
				for(int end=i;end<=k;end++){
					ans+=b[end].rx;
				}
				return;
			}
		}
	}
}
void dfs(int k,long long sum){
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(t[i]<=n/2-1){
			if(i==1){
				t[i]++;
				dfs(k+1,sum+a[k].x);
				t[i]--;
			}
			if(i==2){
				t[i]++;
				dfs(k+1,sum+a[k].y);
				t[i]--;
			}
			if(i==3){
				t[i]++;
				dfs(k+1,sum+a[k].z);
				t[i]--;
			}
		}
	}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
		ans=0;
		bool f=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			sort_max_min(abs(a[i].x-a[i].y),abs(a[i].y-a[i].z),abs(a[i].z-a[i].x),i);
			if(a[i].x!=0&&a[i].y!=0&&a[i].z!=0)f=1;
		}
		if(!f){
			t1=t2=n/2;
			redo3(1);
			cout<<ans<<'\n';
			continue;
		}
		if(n<=15){
			t[1]=t[2]=t[3]=0;
			dfs(1,0);
			cout<<ans<<'\n';
			continue;
		}
		sort(a+1,a+1+n,cmp);
		t1=t2=t3=n/2;
		for(int i=1;i<=n;i++){
			if(a[i].max_cha==a[i].z-a[i].y||a[i].max_cha==a[i].z-a[i].x){
				if(t3!=0){
					t3--;
					ans+=a[i].z;
				}else{
					redo3(i);
					break;
				}
			}else if(a[i].max_cha==a[i].y-a[i].z||a[i].max_cha==a[i].y-a[i].x){
				if(t2!=0){
					t2--;
					ans+=a[i].y;
				}else{
					redo2(i);
					break;
				}
			}else if(a[i].max_cha==a[i].x-a[i].y||a[i].max_cha==a[i].x-a[i].z){
				if(t1!=0){
					t1--;
					ans+=a[i].x;
				}else{
					redo1(i);
					break;
				}
			}
		}
		cout<<ans<<'\n';
    }
	return 0;
}/*
1
4
5 2 1
4 2 0
3 2 1
2 1 3
*/
