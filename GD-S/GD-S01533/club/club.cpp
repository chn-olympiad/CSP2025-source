#include<bits/stdc++.h>
using namespace std;
struct club{
	int a,b,c;
};
struct dp{
	int maxx,ax,bx,cx;
};
bool cmp1(club a,club b){
	return a.a==b.a&&(a.b==b.b&&a.c>b.c||a.b>b.b)||a.a>b.a;
}
bool cmp2(club a,club b){
	return a.a==b.a&&(a.c==b.c&&a.b>b.b||a.c>b.c)||a.a>b.a;
}
bool cmp3(club a,club b){
	return a.b==b.b&&(a.a==b.a&&a.c>b.c||a.a>b.a)||a.b>b.b;
}
bool cmp4(club a,club b){
	return a.b==b.b&&(a.c==b.c&&a.a>b.a||a.c>b.c)||a.b>b.b;
}
bool cmp5(club a,club b){
	return a.c==b.c&&(a.a==b.a&&a.b>b.b||a.a>b.a)||a.c>b.c;
}
bool cmp6(club a,club b){
	return a.c==b.c&&(a.b==b.b&&a.a>b.a||a.b>b.b)||a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<club>a(100001);
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		int ans=0;
		{
			sort(a.begin(),a.end(),cmp1);
			vector<vector<dp>>f(100001,vector<dp>(3));
			f[0][0].maxx=a[0].a,f[0][0].ax++;
			f[0][1].maxx=a[0].b,f[0][1].bx++;
			f[0][2].maxx=a[0].c,f[0][2].cx++;
			for(int i=1;i<n;i++){
				for(int k=0;k<3;k++){
					if(f[i-1][k].ax<n/2){
						if(f[i][0].maxx<f[i-1][k].maxx+a[i].a){
							f[i][0].maxx=f[i-1][k].maxx+a[i].a,f[i][0].ax=f[i-1][k].ax+1,f[i][0].bx=f[i-1][k].bx,f[i][0].cx=f[i-1][k].cx;
						}
					}
					if(f[i-1][k].bx<n/2){
						if(f[i][1].maxx<f[i-1][k].maxx+a[i].b){
							f[i][1].maxx=f[i-1][k].maxx+a[i].b,f[i][1].ax=f[i-1][k].ax,f[i][1].bx=f[i-1][k].bx+1,f[i][1].cx=f[i-1][k].cx;
						}
					}
					if(f[i-1][k].cx<n/2){
						if(f[i][2].maxx<f[i-1][k].maxx+a[i].c){
							f[i][2].maxx=f[i-1][k].maxx+a[i].c,f[i][2].ax=f[i-1][k].ax,f[i][2].bx=f[i-1][k].bx,f[i][2].cx=f[i-1][k].cx+1;
						}
					}
				}
			}
			ans=max(ans,max(max(f[n-1][0].maxx,f[n-1][1].maxx),f[n-1][2].maxx));
		}
		{
			sort(a.begin(),a.end(),cmp2);
			vector<vector<dp>>f(100001,vector<dp>(3));
			f[0][0].maxx=a[0].a,f[0][0].ax++;
			f[0][1].maxx=a[0].b,f[0][1].bx++;
			f[0][2].maxx=a[0].c,f[0][2].cx++;
			for(int i=1;i<n;i++){
				for(int k=0;k<3;k++){
					if(f[i-1][k].ax<n/2){
						if(f[i][0].maxx<f[i-1][k].maxx+a[i].a){
							f[i][0].maxx=f[i-1][k].maxx+a[i].a,f[i][0].ax=f[i-1][k].ax+1,f[i][0].bx=f[i-1][k].bx,f[i][0].cx=f[i-1][k].cx;
						}
					}
					if(f[i-1][k].bx<n/2){
						if(f[i][1].maxx<f[i-1][k].maxx+a[i].b){
							f[i][1].maxx=f[i-1][k].maxx+a[i].b,f[i][1].ax=f[i-1][k].ax,f[i][1].bx=f[i-1][k].bx+1,f[i][1].cx=f[i-1][k].cx;
						}
					}
					if(f[i-1][k].cx<n/2){
						if(f[i][2].maxx<f[i-1][k].maxx+a[i].c){
							f[i][2].maxx=f[i-1][k].maxx+a[i].c,f[i][2].ax=f[i-1][k].ax,f[i][2].bx=f[i-1][k].bx,f[i][2].cx=f[i-1][k].cx+1;
						}
					}
				}
			}
			ans=max(ans,max(max(f[n-1][0].maxx,f[n-1][1].maxx),f[n-1][2].maxx));
		}
		{
			sort(a.begin(),a.end(),cmp3);
			vector<vector<dp>>f(100001,vector<dp>(3));
			f[0][0].maxx=a[0].a,f[0][0].ax++;
			f[0][1].maxx=a[0].b,f[0][1].bx++;
			f[0][2].maxx=a[0].c,f[0][2].cx++;
			for(int i=1;i<n;i++){
				for(int k=0;k<3;k++){
					if(f[i-1][k].ax<n/2){
						if(f[i][0].maxx<f[i-1][k].maxx+a[i].a){
							f[i][0].maxx=f[i-1][k].maxx+a[i].a,f[i][0].ax=f[i-1][k].ax+1,f[i][0].bx=f[i-1][k].bx,f[i][0].cx=f[i-1][k].cx;
						}
					}
					if(f[i-1][k].bx<n/2){
						if(f[i][1].maxx<f[i-1][k].maxx+a[i].b){
							f[i][1].maxx=f[i-1][k].maxx+a[i].b,f[i][1].ax=f[i-1][k].ax,f[i][1].bx=f[i-1][k].bx+1,f[i][1].cx=f[i-1][k].cx;
						}
					}
					if(f[i-1][k].cx<n/2){
						if(f[i][2].maxx<f[i-1][k].maxx+a[i].c){
							f[i][2].maxx=f[i-1][k].maxx+a[i].c,f[i][2].ax=f[i-1][k].ax,f[i][2].bx=f[i-1][k].bx,f[i][2].cx=f[i-1][k].cx+1;
						}
					}
				}
			}
			ans=max(ans,max(max(f[n-1][0].maxx,f[n-1][1].maxx),f[n-1][2].maxx));
		}
		{
			sort(a.begin(),a.end(),cmp4);
			vector<vector<dp>>f(100001,vector<dp>(3));
			f[0][0].maxx=a[0].a,f[0][0].ax++;
			f[0][1].maxx=a[0].b,f[0][1].bx++;
			f[0][2].maxx=a[0].c,f[0][2].cx++;
			for(int i=1;i<n;i++){
				for(int k=0;k<3;k++){
					if(f[i-1][k].ax<n/2){
						if(f[i][0].maxx<f[i-1][k].maxx+a[i].a){
							f[i][0].maxx=f[i-1][k].maxx+a[i].a,f[i][0].ax=f[i-1][k].ax+1,f[i][0].bx=f[i-1][k].bx,f[i][0].cx=f[i-1][k].cx;
						}
					}
					if(f[i-1][k].bx<n/2){
						if(f[i][1].maxx<f[i-1][k].maxx+a[i].b){
							f[i][1].maxx=f[i-1][k].maxx+a[i].b,f[i][1].ax=f[i-1][k].ax,f[i][1].bx=f[i-1][k].bx+1,f[i][1].cx=f[i-1][k].cx;
						}
					}
					if(f[i-1][k].cx<n/2){
						if(f[i][2].maxx<f[i-1][k].maxx+a[i].c){
							f[i][2].maxx=f[i-1][k].maxx+a[i].c,f[i][2].ax=f[i-1][k].ax,f[i][2].bx=f[i-1][k].bx,f[i][2].cx=f[i-1][k].cx+1;
						}
					}
				}
			}
			ans=max(ans,max(max(f[n-1][0].maxx,f[n-1][1].maxx),f[n-1][2].maxx));
		}
		{
			sort(a.begin(),a.end(),cmp5);
			vector<vector<dp>>f(100001,vector<dp>(3));
			f[0][0].maxx=a[0].a,f[0][0].ax++;
			f[0][1].maxx=a[0].b,f[0][1].bx++;
			f[0][2].maxx=a[0].c,f[0][2].cx++;
			for(int i=1;i<n;i++){
				for(int k=0;k<3;k++){
					if(f[i-1][k].ax<n/2){
						if(f[i][0].maxx<f[i-1][k].maxx+a[i].a){
							f[i][0].maxx=f[i-1][k].maxx+a[i].a,f[i][0].ax=f[i-1][k].ax+1,f[i][0].bx=f[i-1][k].bx,f[i][0].cx=f[i-1][k].cx;
						}
					}
					if(f[i-1][k].bx<n/2){
						if(f[i][1].maxx<f[i-1][k].maxx+a[i].b){
							f[i][1].maxx=f[i-1][k].maxx+a[i].b,f[i][1].ax=f[i-1][k].ax,f[i][1].bx=f[i-1][k].bx+1,f[i][1].cx=f[i-1][k].cx;
						}
					}
					if(f[i-1][k].cx<n/2){
						if(f[i][2].maxx<f[i-1][k].maxx+a[i].c){
							f[i][2].maxx=f[i-1][k].maxx+a[i].c,f[i][2].ax=f[i-1][k].ax,f[i][2].bx=f[i-1][k].bx,f[i][2].cx=f[i-1][k].cx+1;
						}
					}
				}
			}
			ans=max(ans,max(max(f[n-1][0].maxx,f[n-1][1].maxx),f[n-1][2].maxx));
		}
		{
			sort(a.begin(),a.end(),cmp6);
			vector<vector<dp>>f(100001,vector<dp>(3));
			f[0][0].maxx=a[0].a,f[0][0].ax++;
			f[0][1].maxx=a[0].b,f[0][1].bx++;
			f[0][2].maxx=a[0].c,f[0][2].cx++;
			for(int i=1;i<n;i++){
				for(int k=0;k<3;k++){
					if(f[i-1][k].ax<n/2){
						if(f[i][0].maxx<f[i-1][k].maxx+a[i].a){
							f[i][0].maxx=f[i-1][k].maxx+a[i].a,f[i][0].ax=f[i-1][k].ax+1,f[i][0].bx=f[i-1][k].bx,f[i][0].cx=f[i-1][k].cx;
						}
					}
					if(f[i-1][k].bx<n/2){
						if(f[i][1].maxx<f[i-1][k].maxx+a[i].b){
							f[i][1].maxx=f[i-1][k].maxx+a[i].b,f[i][1].ax=f[i-1][k].ax,f[i][1].bx=f[i-1][k].bx+1,f[i][1].cx=f[i-1][k].cx;
						}
					}
					if(f[i-1][k].cx<n/2){
						if(f[i][2].maxx<f[i-1][k].maxx+a[i].c){
							f[i][2].maxx=f[i-1][k].maxx+a[i].c,f[i][2].ax=f[i-1][k].ax,f[i][2].bx=f[i-1][k].bx,f[i][2].cx=f[i-1][k].cx+1;
						}
					}
				}
			}
			ans=max(ans,max(max(f[n-1][0].maxx,f[n-1][1].maxx),f[n-1][2].maxx));
		}
		cout<<ans<<endl;
	}
	return 0;
} 
