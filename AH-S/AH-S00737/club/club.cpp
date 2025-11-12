#include<bits/stdc++.h>
using namespace std;
long long T;
struct num{
	long long x,y,z;
}a[100010];
struct num2{
	long long d,id;
}x[100010],y[100010],z[100010];
bool cmp(const num2 &x,const num2 &y){
	return x.d<y.d;
}
queue<num2> lost;
long long mid(long long id){
	if(a[id].x<a[id].y&&a[id].x>a[id].z){
		return 1;
	}
	if(a[id].y<a[id].x&&a[id].y>a[id].z){
		return 2;
	}
	return 3;
}
long long maxn(long long id){
	if(a[id].x>a[id].y&&a[id].x>a[id].z){
		return 1;
	}
	if(a[id].y>a[id].x&&a[id].y>a[id].z){
		return 2;
	}
	return 3;
}
long long minn(long long id){
	if(a[id].x<a[id].y&&a[id].x<a[id].z){
		return 1;
	}
	if(a[id].y<a[id].x&&a[id].y<a[id].z){
		return 2;
	}
	return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		long long n,ans=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y&&a[i].x>a[i].z){
				x[++cnt1].d=a[i].x;
				x[cnt1].id=i;
			}
			if(a[i].y>a[i].x&&a[i].y>a[i].z){
				y[++cnt2].d=a[i].y;
				y[cnt2].id=i;
			}
			if(a[i].z>a[i].x&&a[i].z>a[i].y){
				z[++cnt3].d=a[i].z;
				z[cnt3].id=i;
			}
		}
		if(n==2){
			long long maxn1=max(a[1].x+a[2].y,a[1].x+a[2].z);
			long long maxn2=max(a[1].y+a[2].x,a[1].y+a[2].z);
			long long maxn3=max(a[1].z+a[2].x,a[1].z+a[2].y);
			cout<<max(maxn1,max(maxn2,maxn3));
			continue;
		}
		sort(x+1,x+cnt1+1,cmp);
		sort(y+1,y+cnt2+1,cmp);
		sort(z+1,z+cnt3+1,cmp);
		long long l1=0,l2=0,l3=0,s1=cnt1,s2=cnt2,s3=cnt3;
		for(long long i=1;i<=n/2;i++){
			if(cnt1>0){
				ans+=x[cnt1].d;
				cnt1--;
			}
			else l1++;
			if(cnt2>0){
				ans+=y[cnt2].d;
				cnt2--;
			}
			else l2++;
			if(cnt3>0){
				ans+=z[cnt3].d;
				cnt3--;
			}
			else l3++;
		}
		long long j1=0,j2=0,j3=0;
		if(l1==0&&s1>n/2){
			for(long long i=n/2;i<=s1;i++){
				long long now=ans-x[i].d+x[n/2-j1].d;
				if(mid(x[i].id)==2&&l2>0){
					if(now+a[x[i].id].y>ans){
						ans=now+a[x[i].id].y;
						j1++;
						cnt1--;
						l2--;
						l1++;
						x[i].id=-1;
					}
				}
				else if(now+a[x[i].id].z>ans&&l3>0){
					ans=now+a[x[i].id].z;
					j1++;
					cnt1--;
					l3--;
					l1++;
					x[i].id=-1;
				}
			}
		}
		if(l2==0&&s2>n/2){
			for(long long i=n/2;i<=s2;i++){
				long long now=ans-y[i].d+y[n/2-j2].d;
				if(mid(y[i].id)==1&&l1>0){
					if(now+a[y[i].id].x>ans){
						ans=now+a[y[i].id].x;
						j2++;
						cnt2--;
						l1--;
						l2++;
						y[i].id=-1;
					}
				}
				else if(now+a[y[i].id].z>ans&&l3>0){
					ans=now+a[y[i].id].z;
					j1++;
					cnt1--;
					l3--;
					l2++;
					y[i].id=-1;
				}
			}
		}
		if(l3==0&&s3>n/2){
			for(long long i=n/2;i<=s3;i++){
				long long now=ans-z[i].d+z[n/2-j3].d;
				if(mid(z[i].id)==1&&l1>0){
					if(now+a[z[i].id].x>ans){
						ans=now+a[z[i].id].x;
						j3++;
						cnt3--;
						l1--;
						l3++;
						z[i].id=-1;
					}
				}
				else if(now+a[z[i].id].z>ans&&l2>0){
					ans=now+a[z[i].id].z;
					j1++;
					cnt1--;
					l2--;
					l3++;
					z[i].id=-1;
				}
			}
		}
		for(long long i=1;i<=cnt1;i++) lost.push(x[i]);
		for(long long i=1;i<=cnt2;i++) lost.push(y[i]);
		for(long long i=1;i<=cnt3;i++) lost.push(z[i]);
		long long l=lost.size();
		for(long long i=1;i<=l;i++){
			long long id=lost.front().id;
			if(id==-1){
				lost.pop();
				continue;
			}
			if(mid(id)==1){
				if(l1==0){
					if(minn(id)==2) ans+=a[id].y;
					else ans+=a[id].z;
				}
				else ans+=a[id].x;
			}
			else if(mid(id)==2){
				if(l2==0){
					if(minn(id)==1) ans+=a[id].x;
					else ans+=a[id].z;
				}
				else ans+=a[id].y;
			}
			else{
				if(l3==0){
					if(minn(id)==1) ans+=a[id].x;
					else ans+=a[id].y;
				}
				else ans+=a[id].z;
			}
			lost.pop();
		}
		cout<<ans<<endl;
	}
	return  0;
}
