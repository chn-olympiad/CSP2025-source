#include<bits/stdc++.h>
using namespace std;
int a[100001][4],m[100001];
int f[100001][4],sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2]){
				if(a[i][1]<a[i][3]){
					m[i]=3;
				}
				if(a[i][1]>a[i][3]){
					m[i]=1;
				}
			}
			if(a[i][1]<a[i][2]){
				if(a[i][2]<a[i][3]){
					m[i]=3;
				}
				if(a[i][2]>a[i][3]){
					m[i]=2;
				}
			}
		}
		int fa=0,fb=0,fc=0;
		for(int i=1;i<=n;i++){
			if(m[i]==1){
				if(fa<n/2){
					f[++fa][1]=i;
				}else{
					int minn=a[f[fa][1]][1]-max(a[f[fa][1]][2],a[f[fa][1]][3]),minf=f[fa][1];
					for(int j=1;j<=fa;j++){
						if(a[f[j][1]][1]-max(a[f[fa][1]][2],a[f[fa][1]][3])==minn){
							int maxa=max(a[f[j][1]][2],a[f[j][1]][3]),maxb=max(a[minf][2],a[minf][3]);
							if(maxa<maxb){
								minn=a[f[j][1]][1]-max(a[f[fa][1]][2],a[f[fa][1]][3]);
								minf=f[j][1];
							}
						}else if(a[f[j][1]][1]-max(a[f[fa][1]][2],a[f[fa][1]][3])<minn){
							minn=a[f[j][1]][1]-max(a[f[fa][1]][2],a[f[fa][1]][3]);
							minf=f[j][1];
						}
					}
					int maxa=max(a[i][2],a[i][3]),maxb=max(a[minf][2],a[minf][3]);
					if(maxb+a[i][1]>maxa+a[minf][1]){
						if(a[minf][2]>a[minf][3]){
							f[++fb][2]=i;
						}else{
							f[++fc][3]=i;
						}
						swap(a[minf][1],a[i][1]);
						swap(a[minf][2],a[i][2]);
						swap(a[minf][3],a[i][3]);
					}
				}
			}else if(m[i]==2){
				if(fb<n/2){
					f[++fb][2]=i;
				}else{
					int minn=a[f[fb][2]][2]-max(a[f[fb][2]][1],a[f[fb][2]][3]),minf=f[fb][2];
					for(int j=1;j<=fb;j++){
						if(a[f[j][2]][2]-max(a[f[fb][2]][1],a[f[fb][2]][3])==minn){
							int maxa=max(a[f[j][2]][1],a[f[j][2]][3]),maxb=max(a[minf][1],a[minf][3]);
							if(maxa<maxb){
								minn=a[f[j][2]][2]-max(a[f[fb][2]][1],a[f[fb][2]][3]);
								minf=f[j][2];
							}
						}else if(a[f[j][2]][2]-max(a[f[fb][2]][1],a[f[fb][2]][3])<minn){
							minn=a[f[j][2]][2]-max(a[f[fb][2]][1],a[f[fb][2]][3]);
							minf=f[j][2];
						}
					}
					int maxa=max(a[i][1],a[i][3]),maxb=max(a[minf][1],a[minf][3]);
					if(maxb+a[i][2]>maxa+a[minf][2]){
						if(a[minf][1]>a[minf][3]){
							f[++fa][1]=i;
						}else{
							f[++fc][3]=i;
						}
						swap(a[minf][1],a[i][1]);
						swap(a[minf][2],a[i][2]);
						swap(a[minf][3],a[i][3]);
					}
				}
				
			}else if(m[i]==3){
				if(fc<n/2){
					f[++fc][3]=i;
				}else{
					int minn=a[f[fc][3]][3]-max(a[f[fc][3]][1],a[f[fc][3]][2]),minf=f[fc][3];
					for(int j=1;j<=fc;j++){
						if(a[f[j][3]][3]-max(a[f[j][3]][1],a[f[j][3]][2])==minn){
							int maxa=max(a[f[j][3]][1],a[f[j][3]][2]),maxb=max(a[minf][1],a[minf][2]);
							if(maxa<maxb){
								minn=a[f[j][3]][3]-max(a[f[j][3]][1],a[f[j][3]][2]);
								minf=f[j][3];
							}
						}else if(a[f[j][3]][3]-max(a[f[j][3]][1],a[f[j][3]][2])<minn){
							minn=a[f[j][3]][3]-max(a[f[j][3]][1],a[f[j][3]][2]);
							minf=f[j][3];
						}
					}
					if(minf==i){
						if(a[minf][1]>a[minf][2]){
							f[++fa][1]=i;
						}else{
							f[++fb][2]=i;
						}
					}else{
						int maxa=max(a[i][1],a[i][2]),maxb=max(a[minf][1],a[minf][2]);
						if(maxb+a[i][3]>maxa+a[minf][3]){
							if(a[minf][1]>a[minf][2]){
								f[++fa][1]=i;
							}else{
								f[++fb][2]=i;
							}
							swap(a[minf][1],a[i][1]);
							swap(a[minf][2],a[i][2]);
							swap(a[minf][3],a[i][3]);
						}
					}
				}
				
			}
		}
		for(int i=1;i<=fa;i++){
			sum+=a[f[i][1]][1];
			f[i][1]=0;
		}
		for(int i=1;i<=fb;i++){
			sum+=a[f[i][2]][2];
			f[i][2]=0;
		}
		for(int i=1;i<=fc;i++){
			sum+=a[f[i][3]][3];
			f[i][3]=0;
		}
		cout<<sum<<endl;
		sum=0;
		
//		f[i][j]=max(a[i][j],a[i][j+1]+a[i+1][j]);
		
	}
	return 0;
}
