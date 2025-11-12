#include<bits/stdc++.h>
using namespace std;
struct stu{
	int x,y,z;
}a[100010];
int T,n,ans,tmp,t[4],k[4],la;
bool cmp(const stu&k,const stu&w){
	//if(max({k.x,k.y,k.z})!=max({w.x,w.y,w.z}))return max({k.x,k.y,k.z})>max({w.x,w.y,w.z});
	int q=max({k.x,k.y,k.z}),qwq=max({w.x,w.y,w.z}),xx,yy;
	if(k.x==q){
		if(k.y){
			xx=k.y;
		}else{
			xx=k.z;
		}
	}else if(k.y==q){
		if(k.x){
			xx=k.x;
		}else{
			xx=k.z;
		}
	}else{
		if(k.x){
			xx=k.x;
		}else{
			xx=k.y;
		}
	}if(w.x==qwq){
		if(w.y){
			yy=w.y;
		}else{
			yy=w.z;
		}
	}else if(w.y==qwq){
		if(w.x){
			yy=w.x;
		}else{
			yy=w.z;
		}
	}else{
		if(w.x){
			yy=w.x;
		}else{
			yy=w.y;
		}
	}
	return q-xx>qwq-yy;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		t[1]=t[2]=t[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			tmp=min({a[i].x,a[i].y,a[i].z});
			ans+=tmp;
			a[i].x-=tmp;
			a[i].y-=tmp;
			a[i].z-=tmp;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			la=ans;
			k[1]=a[i].x,k[2]=a[i].y,k[3]=a[i].z;
			sort(k+1,k+4);
			if(a[i].x==k[3]){
				if(t[1]<n/2){
					t[1]++;
					ans+=k[3];
				}else{
					if(a[i].y==k[2]){
						if(t[2]<n/2){
							t[2]++,ans+=k[2];
						}
						else t[3]++,ans+=k[1];
					}else{
						if(t[3]<n/2){
							t[3]++,ans+=k[2];
						}
						else t[2]++,ans+=k[1];
					}
				}
			}else if(a[i].y==k[3]){
				if(t[2]<n/2){
					t[2]++;
					ans+=k[3];
				}else{
					if(a[i].x==k[2]){
						if(t[1]<n/2){
							t[1]++,ans+=k[2];
						}
						else t[3]++,ans+=k[1];
					}else{
						if(t[3]<n/2){
							t[3]++,ans+=k[2];
						}
						else t[1]++,ans+=k[1];
					}
				}
			}else{
				if(t[3]<n/2){
					t[3]++;
					ans+=k[3];
				}else{
					if(a[i].y==k[2]){
						if(t[2]<n/2){
							t[2]++,ans+=k[2];
						}
						else t[1]++,ans+=k[1];
					}else{
						if(t[1]<n/2){
							t[1]++,ans+=k[2];
						}
						else t[2]++,ans+=k[1];
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
