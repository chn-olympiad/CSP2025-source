#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
int f[N][4];
int s1,s2,s3;
int t,n,ans;

struct node{
	int x,y,z;
}a[N],b[N],c[N];

bool cmp1(node f1,node f2){
	return f1.x>f2.x;
}
//bool cmp2(node a,node b) return a.y>b.y;
//bool cmp3(node a,node b) return a.z>b.z;

int dfs(int c,int d,int sum,int f1,int f2,int f3){
	//第c个成员，分配到d，当前总满意度，三门课各有成员数 
	if(c==n){
		if(d==1) sum+=a[c].x,f1++;
		if(d==2) sum+=a[c].y,f2++;
		if(d==3) sum+=a[c].z,f3++;
		if(f1>n/2||f2>n/2||f3>n/2) return -1;
		return sum;
	}
	if(d==1) sum+=a[c].x,f1++;
	if(d==2) sum+=a[c].y,f2++;
	if(d==3) sum+=a[c].z,f3++;
	if(f1>n/2||f2>n/2||f3>n/2) return -1;
//	cout<<c<<' '<<d<<' '<<sum<<' '<<f1<<' '<<f2<<' '<<f3<<'\n';
	sum=max(max(dfs(c+1,1,sum,f1,f2,f3),dfs(c+1,2,sum,f1,f2,f3)),dfs(c+1,3,sum,f1,f2,f3));
//	cout<<sum<<'\n';
	return sum;
} 

bool cmp4(int f1,int f2){
	return a[f1].x>a[f2].x;
}

bool cmp5(int f1,int f2){
	return a[f1].y>a[f2].y;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y>>a[i].z;
		b[i]=a[i],c[i]=a[i];
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z) s1++;
		if(a[i].y>=a[i].x&&a[i].y>=a[i].z) s2++;
		if(a[i].z>=a[i].y&&a[i].z>=a[i].x) s3++;
	}
	if(s1<=n/2&&s2<=n/2&&s3<=n/2){
		for(int i=1;i<=n;++i){
			ans+=max(a[i].x,max(a[i].y,a[i].z));
		}
		cout<<ans;
		return;
	}
	if(s1==n){
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n/2;++i) ans+=a[i].x;
		cout<<ans<<'\n';
		return;
	}
	if(s1+s2==n){
		int f[N]={},z;
		if(s1>s2){
			for(int i=1;i<=n;++i){
				if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
					f[++z]=i;
				}
			}
			sort(f+1,f+1+z,cmp4);
			for(int i=1;i<=n/2;++i){
				ans+=a[i].x;
			}
			for(int i=n/2+1;i<=n;++i){
				ans+=a[i].y;
			}
		}else if(s1<s2){
			for(int i=1;i<=n;++i){
				if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
					f[++z]=i;
				}
			}
			sort(f+1,f+1+z,cmp5);
			for(int i=1;i<=n/2;++i){
				ans+=a[i].y;
			}
			for(int i=n/2+1;i<=n;++i){
				ans+=a[i].x;
			}
		}else{
			for(int i=1;i<=n/2;++i){
				if(a[i].y>=a[i].x){
					ans+=a[i].y;
				}else{
					ans+=a[i].x;
				}
			}
		}
		cout<<ans<<'\n';
		return;
	}
	if(n<=10){
		cout<<max(dfs(1,1,0,0,0,0),max(dfs(1,2,0,0,0,0),dfs(1,3,0,0,0,0)))<<'\n';
		return;
	}
//	if(s1==n/2)
//	for(int i=1;i<=n;++i){
//		if(f[i]==1) 
//	}
//	sort(a+1,a+1+n,cmp1);
//	sort(b+1,b+1+n,cmp2);
//	sort(c+1,c+1+n,cmp3);
//	for(int i=1;i<=n;++i){
//		f[a[i].id][1]=i;
//		f[b[i].id][2]=i;
//		f[c[i].id][3]=i;
//	}
//	for(int i=1;i<=n;++i){
//		int f1=f[i][1],f2=f[i][2],f3=f[i][3];
//		if(f1<f2&&f1<f3&&a[f1].x>b[f2].y&&a[f1].x>c[f3].z){
//			
//		}
//	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
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
*/

/*
特殊性质A+B:

in:
2
4
5 0 0
3 0 0
7 0 0
1 0 0
4
1 1 0
2 1 0
4 9 0
3 1 0

output:
12
15


*/

/*

哈喽你可以看到我写了这么多只写了40pts
^^甚至是不保证正确性 

*/

/*
前面忘了，想了很多，中间忘了，后面忘了。
#66CCFF 

*/

/*
这里是友情垫底。
想上HN迷惑行为大赏 /kel 

代码已经够整活了吧（？） 

RP+=INF
*/ 
