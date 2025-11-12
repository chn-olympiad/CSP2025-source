#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int inf=0x3f3f3f3f;
inline int read(){
	char ch=getchar();
	int f=1,s=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	return f*s;
} 
int T,n,m,f[205][205][205];
struct node{
	int x,y,z;
}a[N];
bool cmp1(node A,node B){
	if(A.x!=B.x)return A.x>B.x;
	else if(A.y!=B.y)return A.y>B.y;
	else return A.z>B.z;
}
bool cmp2(node A,node B){
	if(A.x!=B.x)return A.x>B.x;
	else if(A.z!=B.z)return A.z>B.z;
	else return A.y>B.y;
}
bool cmp3(node A,node B){
	if(A.y!=B.y)return A.y>B.y;
	else if(A.x!=B.x)return A.x>B.x;
	else return A.z>B.z;
}
bool cmp4(node A,node B){
	if(A.y!=B.y)return A.y>B.y;
	else if(A.z!=B.z)return A.z>B.z;
	else return A.x>B.x;
}
bool cmp5(node A,node B){
	if(A.z!=B.z)return A.z>B.z;
	else if(A.x!=B.x)return A.x>B.x;
	else return A.y>B.y;
}
bool cmp6(node A,node B){
	if(A.z!=B.z)return A.z>B.z;
	else if(A.y!=B.y)return A.y>B.y;
	else return A.x>B.x;
}
bool cmp7(node A,node B){
	return max(max(A.x,A.y),A.z)>max(max(B.x,B.y),B.z);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		memset(f,0,sizeof(f));
		n=read();
		int Lim=n/2;
		bool fl=0;
		for(int i=1;i<=n;i++){
			a[i].x=read();
			a[i].y=read();
			a[i].z=read();
			if(a[i].y||a[i].z)fl=1;
		}
		if(!fl){
			sort(a+1,a+n+1,cmp1);
			int tmp=0;
			for(int i=1;i<=Lim;i++){
				tmp+=a[i].x;
			}
			printf("%lld\n",tmp);
			continue;
		}
		int mxx=0;
		if(n<=200){
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,Lim);j++){
					for(int k=max(0ll,i-Lim-j);k<=min(i,Lim)&&j+k<=i;k++){
						if(j==0&&k==0){
							if(i<Lim)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
						}
						else if(j==0){
							if(i-1-j-k+1<=Lim)f[i][j][k]=max(f[i-1][j][k-1]+a[i].y,f[i][j][k]);
							if(i-1-j-k<=Lim&&i-1-j-k>=0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
						}
						else if(k==0){
							if(i-1-j+1-k<=Lim)f[i][j][k]=max(f[i-1][j-1][k]+a[i].x,f[i][j][k]);
							if(i-1-j-k<=Lim&&i-1-j-k>=0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i].z);
						}
						else {
							if(i-1-j+1-k<=Lim)f[i][j][k]=max(f[i-1][j-1][k]+a[i].x,f[i][j][k]);
							if(i-1-j-k+1<=Lim)f[i][j][k]=max(f[i-1][j][k-1]+a[i].y,f[i][j][k]);
							if(i-1-j-k<=Lim&&i-1-j-k>=0)f[i][j][k]=max(f[i-1][j][k]+a[i].z,f[i][j][k]);
						}
						if(i==n)mxx=max(mxx,f[i][j][k]);
					}	
				}
			}
		}
		int A=0,B=0,C=0,ans=0;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(A>=Lim){
				if(B>=Lim){
					ans+=a[i].z;
					C++;	
				}
				else {
					ans+=a[i].y;
					B++;
				}
			}
			else {
				A++;
				ans+=a[i].x;
			}
		}
		mxx=max(mxx,ans);
		A=0,B=0,C=0,ans=0;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(A>=Lim){
				if(B>=Lim){
					ans+=a[i].y;
					C++;	
				}
				else {
					ans+=a[i].z;
					B++;
				}
			}
			else {
				A++;
				ans+=a[i].x;
			}
		}
		mxx=max(mxx,ans);
		A=0,B=0,C=0,ans=0;
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(A>=Lim){
				if(B>=Lim){
					ans+=a[i].z;
					C++;	
				}
				else {
					ans+=a[i].x;
					B++;
				}
			}
			else {
				A++;
				ans+=a[i].y;
			}
		}
		mxx=max(mxx,ans);
		A=0,B=0,C=0,ans=0;
		sort(a+1,a+n+1,cmp4);
		for(int i=1;i<=n;i++){
			if(A>=Lim){
				if(B>=Lim){
					ans+=a[i].x;
					C++;	
				}
				else {
					ans+=a[i].z;
					B++;
				}
			}
			else {
				A++;
				ans+=a[i].y;
			}
		}
		mxx=max(mxx,ans);
		A=0,B=0,C=0,ans=0;
		sort(a+1,a+n+1,cmp5);
		for(int i=1;i<=n;i++){
			if(A>=Lim){
				if(B>=Lim){
					ans+=a[i].y;
					C++;	
				}
				else {
					ans+=a[i].x;
					B++;
				}
			}
			else {
				A++;
				ans+=a[i].z;
			}
		}
		mxx=max(mxx,ans);
		A=0,B=0,C=0,ans=0;
		sort(a+1,a+n+1,cmp6);
		for(int i=1;i<=n;i++){
			if(A>=Lim){
				if(B>=Lim){
					ans+=a[i].x;
					C++;	
				}
				else {
					ans+=a[i].y;
					B++;
				}
			}
			else {
				A++;
				ans+=a[i].z;
			}
		}
		mxx=max(mxx,ans);
		A=0,B=0,C=0,ans=0;
		sort(a+1,a+n+1,cmp7);
		for(int i=1;i<=n;i++){
			int d=max(max(a[i].x,a[i].y),a[i].z);
			if(d==a[i].x){
				if(A<Lim){
					A++;
					ans+=d;
				}
				else {
					int d1=max(a[i].y,a[i].z);
					if(d1==a[i].y){
						if(B<Lim){
							B++;
							ans+=d1;
						}
						else {
							C++;
							ans+=a[i].z;
						}
					}
					if(d1==a[i].z){
						if(C<Lim){
							C++;
							ans+=d1;
						}
						else {
							B++;
							ans+=a[i].y;
						}
					}
				}
			}
			else if(d==a[i].y){
				if(B<Lim){
					B++;
					ans+=d;
				}
				else {
					int d1=max(a[i].x,a[i].z);
					if(d1==a[i].x){
						if(A<Lim){
							A++;
							ans+=d1;
						}
						else {
							C++;
							ans+=a[i].z;
						}
					}
					if(d1==a[i].z){
						if(C<Lim){
							C++;
							ans+=d1;
						}
						else {
							A++;
							ans+=a[i].x;
						}
					}
				}
			}
			else if(d==a[i].z){
				if(C<Lim){
					C++;
					ans+=d;
				}
				else {
					int d1=max(a[i].x,a[i].y);
					if(d1==a[i].x){
						if(A<Lim){
							A++;
							ans+=d1;
						}
						else {
							B++;
							ans+=a[i].y;
						}
					}
					if(d1==a[i].y){
						if(B<Lim){
							B++;
							ans+=d1;
						}
						else {
							A++;
							ans+=a[i].x;
						}
					}
				}
			}
		}
		mxx=max(mxx,ans);
		printf("%lld\n",mxx);
	}
	return 0;
}
