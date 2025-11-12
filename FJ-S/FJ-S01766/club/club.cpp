#include<bits/stdc++.h>
using namespace std;
#define ll long long
int f[100005][5],T,n;
int a[100005][5],b[100005][5],c[100005][5],an,bn,cn,at,bt,ct,xz,t[100005],ans;
signed main(){
	//ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		an=0,bn=0,cn=0,at=0,bt=0,ct=0;
		xz=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&f[i][1],&f[i][2],&f[i][3]);
			if(f[i][3]!=0&&xz==0){
				xz=1;
			}
			if(f[i][2]!=0){
				xz=2;
			}
		}
		if(xz==0){
			memset(t,0,sizeof(t));
			for(int i=1;i<=n;i++){
				t[f[i][1]]++;
			}ans=0,at=n/2;
			for(int i=100000;i>=0;i--){
				if(t[i]){
					while(at>0&&t[i]>0){
						t[i]--;
						at--;
						ans+=i;
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(xz==1){
			ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(f[i][1],f[i][2]);
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				if(f[i][1]>=f[i][2]&&f[i][1]>=f[i][3]){
					an++;
					at+=f[i][1];
					a[an][1]=f[i][1];
					a[an][2]=f[i][2];
					a[an][3]=f[i][3];
				}
				else if(f[i][2]>=f[i][1]&&f[i][2]>=f[i][3]){
					bn++;
					bt+=f[i][2];
					b[bn][1]=f[i][1];
					b[bn][2]=f[i][2];
					b[bn][3]=f[i][3];
				}
				else{
					cn++;
					ct+=f[i][3];
					c[cn][1]=f[i][1];
					c[cn][2]=f[i][2];
					c[cn][3]=f[i][3];
				}
			}
			int p=0,minn=0xfffffff,p2=0;
			while(an>n/2||bn>n/2||cn>n/2){
				p=0,minn=0xfffffff;
				if(an>n/2){
					for(int i=1;i<=an;i++){
						if(a[i][1]-a[i][2]<minn){
							minn=a[i][1]-a[i][2];
							p2=2;
							p=i;
						}
						if(a[i][1]-a[i][3]<minn){
							minn=a[i][1]-a[i][3];
							p2=3;
							p=i;
						}
					}
					if(p2==2){
						bn++;
						b[bn][1]=a[p][1];
						b[bn][2]=a[p][2];
						b[bn][3]=a[p][3];
						bt+=b[bn][2];
						at-=a[p][1];
						an--;
					}
					else{
						cn++;
						c[cn][1]=a[p][1];
						c[cn][2]=a[p][2];
						c[cn][3]=a[p][3];
						ct+=c[cn][3];
						at-=a[p][1];
						an--;
					}
					a[p][1]=a[p][2]=a[p][3]=0;
					for(int i=p;i<=an;i++){
						swap(a[i][1],a[i+1][1]);
						swap(a[i][2],a[i+1][2]);
						swap(a[i][3],a[i+1][3]);
					}
				}
				if(bn>n/2){
					for(int i=1;i<=bn;i++){
						if(b[i][2]-b[i][1]<minn){
							minn=b[i][2]-b[i][1];
							p2=1;
							p=i;
						}
						if(b[i][2]-b[i][3]<minn){
							minn=b[i][2]-b[i][3];
							p2=3;
							p=i;
						}
					}
					if(p2==1){
						an++;
						a[an][1]=b[p][1];
						a[an][2]=b[p][2];
						a[an][3]=b[p][3];
						at+=a[an][1];
						bt-=b[p][2];
						bn--;
					}
					else{
						cn++;
						c[cn][1]=b[p][1];
						c[cn][2]=b[p][2];
						c[cn][3]=b[p][3];
						ct+=c[cn][3];
						bt-=b[p][2];
						bn--;
					}
					b[p][1]=b[p][2]=b[p][3]=0;
					for(int i=p;i<=bn;i++){
						swap(b[i][1],b[i+1][1]);
						swap(b[i][2],b[i+1][2]);
						swap(b[i][3],b[i+1][3]);
					}
				}
				if(cn>n/2){
					for(int i=1;i<=cn;i++){
						if(c[i][3]-c[i][1]<minn){
							minn=c[i][3]-c[i][1];
							p2=1;
							p=i;
						}
						if(c[i][3]-c[i][2]<minn){
							minn=c[i][3]-c[i][2];
							p2=2;
							p=i;
						}
					}
					if(p2==1){
						an++;
						a[an][1]=c[p][1];
						a[an][2]=c[p][2];
						a[an][3]=c[p][3];
						at+=a[an][1];
						ct-=c[p][3];
						cn--;
					}
					else{
						bn++;
						b[cn][1]=b[p][1];
						b[cn][2]=b[p][2];
						b[cn][3]=b[p][3];
						bt+=b[bn][2];
						ct-=c[p][3];
						cn--;
					}
					c[p][1]=c[p][2]=c[p][3]=0;
					for(int i=p;i<=cn;i++){
						swap(c[i][1],c[i+1][1]);
						swap(c[i][2],c[i+1][2]);
						swap(c[i][3],c[i+1][3]);
					}
				}
				
			}cout<<at+bt+ct<<endl;
		}
		
	}
	
	
	cout<<endl;
	return 0;
}
/*
csps_2025_rp++;
idk what actully did i put in the piece of code. hope it works. i only expect 60 pts from this. img this guy played mc till last night and spend 3.5h time in sth useless called cspj.
*/
