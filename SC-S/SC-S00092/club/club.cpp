#include<bits/stdc++.h>
#define int long long 
#define fast int 

using namespace std;

const int N=2e5+100;

int t,n,ans,s1[N],s2[N],s3[N];

struct node{
	int x,y,z;
}a[N];

void dfs(int x,int ca,int cb,int cc,int cnt){
	if (x==n+1){
		ans=max(ans,cnt);
		return;
	}
	if (ca<n/2){
		dfs(x+1,ca+1,cb,cc,cnt+a[x].x);
	}
	if (cb<n/2){
		dfs(x+1,ca,cb+1,cc,cnt+a[x].y);
	}
	if (cc<n/2){
		dfs(x+1,ca,cb,cc+1,cnt+a[x].z);
	}
}

bool cmp(node a,node b){
	if (a.x==b.x&&a.y==b.y) return a.z>b.z;
	else if (a.x==b.x&&a.z==b.z) return a.y>b.y;
	return a.x>b.x;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	std::ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>t;
	
	while(t--){
		int ca=0,cb=0,cc=0;
		
		ans=0;
		memset(s1,0,sizeof s1);
		memset(s2,0,sizeof s2);
		memset(s3,0,sizeof s3);
		
		cin>>n;
		
		for (fast i=1;i<=n;i++) {cin>>a[i].x>>a[i].y>>a[i].z;}
		
		if (n<=10) {ans=-LLONG_MAX;dfs(1,0,0,0,0);cout<<ans<<"\n";continue;}
		
		sort(a+1,a+n+1,cmp);
		
//		for (fast i=1;i<=n;i++){
//			cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<"\n";
//		}
		
		for (fast i=1;i<=n;i++){
			if (a[i].x>=a[i].y&&a[i].x>=a[i].z){
				if (ca<n/2){
					ca++;
					ans+=a[i].x;
					s1[ca]=i;
				}
				else if (ca==n/2){
					int cnt=-LLONG_MAX;
					int flag=0,qwq=0;
					for (fast j=1;j<=ca;j++){
						if (a[s1[j]].x+a[i].y<a[s1[j]].y+a[i].x&&cb<n/2){
							if (a[s1[j]].y+a[i].x-(a[s1[j]].x+a[i].y)>cnt){
								cnt=a[s1[j]].y+a[i].x-(a[s1[j]].x+a[i].y);
								flag=j;
								qwq=1;
							}
						}
						if (a[i].z+a[s1[j]].x<a[i].x+a[s1[j]].z&&cc<n/2){
							if (a[s1[j]].z+a[i].x-(a[s1[j]].x+a[i].z)>cnt){
								cnt=a[s1[j]].z+a[i].x-(a[s1[j]].x+a[i].z);
								flag=j;
								qwq=2;
							}
						}
					}
					if (qwq==1){
						ans+=cnt;
						cb++;
						s2[cb]=flag;
						s1[flag]=i;
						continue;
					}
					if (qwq==2){
						ans+=cnt;
						cc++;
						s3[cc]=flag;
						s1[flag]=i;
						continue;
					}
					if (a[i].z>a[i].y){
						cc++;
						s3[cc]=i;
						ans+=a[i].z;
					}
					else{
						cb++;
						s2[cb]=i;
						ans+=a[i].y;
					}
				}
			}
			if (a[i].y>=a[i].x&&a[i].y>=a[i].z){
				if (cb<n/2){
					cb++;
					ans+=a[i].y;
					s2[cb]=i;
				}
				else if (cb==n/2){
					int cnt=-LLONG_MAX;
					int flag=0,qwq=0;
					for (fast j=1;j<=cb;j++){
						if (a[i].x+a[s2[j]].y<a[i].y+a[s2[j]].x&&ca<n/2){
							if (a[s2[j]].x+a[i].y-(a[s2[j]].y+a[i].x)>cnt){
								cnt=a[s2[j]].x+a[i].y-(a[s2[j]].y+a[i].x);
								flag=j;
								qwq=1;
							}
						}
						if (a[i].z+a[s2[j]].y<a[i].y+a[s2[j]].z&&cc<n/2){
							if (a[s2[j]].z+a[i].y-(a[s2[j]].y+a[i].z)>cnt){
								cnt=a[s2[j]].z+a[i].y-(a[s2[j]].y+a[i].z);
								flag=j;
								qwq=2;
							}
						}
					}
					if (qwq==1){
						ans+=cnt;
						ca++;
						s1[ca]=flag;
						s2[flag]=i;
						continue;
					}
					if (qwq==2){
						ans+=cnt;
						cc++;
						s3[cc]=flag;
						s2[flag]=i;
						continue;
					}
					if (a[i].z>a[i].x){
						cc++;
						s3[cc]=i;
						ans+=a[i].z;
					}
					else{
						ca++;
						s1[ca]=i;
						ans+=a[i].x;
					}
				}
			}
			if (a[i].z>=a[i].x&&a[i].z>=a[i].y){
				if (cc<n/2){
					cc++;
					ans+=a[i].z;
					s3[cc]=i;
				}
				else if (cc==n/2){
					int cnt=-LLONG_MAX;
					int flag=0,qwq=0;
					for (fast j=1;j<=cc;j++){
						if (a[i].x+a[s3[j]].z<a[i].z+a[s2[j]].x&&ca<n/2){
							if (a[s3[j]].x+a[i].z-(a[s3[j]].z+a[i].x)>cnt){
								cnt=a[s3[j]].x+a[i].z-(a[s3[j]].z+a[i].x);
								flag=j;
								qwq=1;
							}
						}
						if (a[i].y+a[s3[j]].z<a[i].z+a[s3[j]].y&&cb<n/2){
							if (a[s3[j]].y+a[i].z-(a[s3[j]].z+a[i].y)>cnt){
								cnt=a[s3[j]].y+a[i].z-(a[s3[j]].z+a[i].y);
								flag=j;
								qwq=2;
							}
						}
					}
					if (qwq==1){
						ans+=cnt;
						ca++;
						s1[ca]=flag;
						s3[flag]=i;
						continue;
					}
					if (qwq==2){
						ans+=cnt;
						cb++;
						s2[cb]=flag;
						s3[flag]=i;
						continue;
					}
					if (a[i].x>a[i].y){
						ca++;
						s1[ca]=i;
						ans+=a[i].x;
					}
					else{
						cb++;
						s2[cb]=i;
						ans+=a[i].y;
					}
				}
			}
		}
		
		for (fast i=1;i<=n;i++) a[i].x=0,a[i].y=0,a[i].z=0;
		
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*

t1这么难 靠 	4:30就不想了

bushi 哥们 阳历1 和 阳历5 都过了 你 阳历 2~4 在干嘛

依旧是

luogu UID: 1072112 and 1371852

1
6
8 2 1
7 0 2
6 5 1
5 0 1
5 0 1
4 0 2
*/