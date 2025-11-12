#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int num,id;
};
int t,n;
int a[N][4];
int f1=0,f2=0,f3=0;
bool cmp1(node a,node b){
	return a.num>b.num;
}
void solve1(){
	int maxx=-1;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i!=j){
				maxx=max(a[1][i]+a[2][j],maxx);
			}
		}
	}
	cout<<maxx<<endl;
}
void solve2(){
	int l[N];
	for(int i=1;i<=n;i++){
		l[i]=a[i][1];
	}
	int ans=0;
	sort(l+1,l+1+n);
	for(int i=n/2+1;i<=n;i++){
		ans+=l[i];
	}
	cout<<ans;
}
void solve3(){
	
}
void solve(){
	int x=0,y=0,z=0;
	int maxx=-1,ans=0;
	for(int i=1;i<=n;i++){
		maxx=-1;
		for(int j=1;j<=3;j++){
			maxx=max(maxx,a[i][j]);
		}
		if(a[i][1]==maxx){
			x++;
			ans+=a[i][1];
		}else if(a[i][2]==maxx){
			y++;
			ans+=a[i][2];
		}else{
			z++;
			ans+=a[i][3];
		}
	}
	if(x<=n/2&&y<=n/2&&z<=n/2) cout<<ans<<endl;
	else{
		node l[N];
		memset(l,0,sizeof(l));
		if(x>n/2){
			for(int i=1;i<=n;i++){
				l[i].num=a[i][1];
				l[i].id=i;
			}
			sort(l+1,l+1+n,cmp1);
			int op=x;
			for(int i=op;i>n/2;i--){
				x--;
				ans-=a[l[i].id][1];
				if(y<n/2&&z<n/2){
					if(a[l[i].id][2]>a[l[i].id][3]){
						ans+=a[l[i].id][2];
						y++;
					}else if(a[l[i].id][2]<a[l[i].id][3]){
						ans+=a[l[i].id][3];
						z++;
					}else{
						if(y>z){
							ans+=a[l[i].id][3];
							z++;
						}else{
							ans+=a[l[i].id][2];
							y++;
						}
					}
				}else if(y<n/2){
					ans+=a[l[i].id][2];
					y++;
				}else if(z<n/2){
					ans+=a[l[i].id][3];
					z++;
				}
			}
		}
		if(y>n/2){
			for(int i=1;i<=n;i++){
				l[i].num=a[i][2];
				l[i].id=i;
			}
			sort(l+1,l+1+n,cmp1);
			int op=y;
			for(int i=op;i>n/2;i--){
				y--;
				ans-=a[l[i].id][2];
				if(x<n/2&&z<n/2){
					if(a[l[i].id][1]>a[l[i].id][3]){
						ans+=a[l[i].id][1];
						x++;
					}else if(a[l[i].id][1]<a[l[i].id][3]){
						ans+=a[l[i].id][3];
						z++;
					}else{
						if(x>z){
							ans+=a[l[i].id][3];
							z++;
						}else{
							ans+=a[l[i].id][1];
							x++;
						}
					}
				}else if(x<n/2){
					ans+=a[l[i].id][1];
					x++;
				}else if(z<n/2){
					ans+=a[l[i].id][3];
					z++;
				}
			}
		}
		if(z>n/2){
			for(int i=1;i<=n;i++){
				l[i].num=a[i][3];
				l[i].id=i;
			}
			sort(l+1,l+1+n,cmp1);
			int op=z;
			for(int i=op;i>n/2;i--){
				z--;
				ans-=a[l[i].id][3];
				if(x<n/2&&y<n/2){
					if(a[l[i].id][1]>a[l[i].id][2]){
						ans+=a[l[i].id][1];
						x++;
					}else if(a[l[i].id][1]<a[l[i].id][2]){
						ans+=a[l[i].id][2];
						y++;
					}else{
						if(f1==0){
							ans+=a[l[i].id][2];
							y++;
						}else{
							ans+=a[l[i].id][1];
							x++;
						}
					}
				}else if(y<n/2){
					ans+=a[l[i].id][2];
					y++;
				}else if(x<n/2){
					ans+=a[l[i].id][1];
					x++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][1]!=0) f1=1;
			if(a[i][2]!=0) f2=1;
			if(a[i][3]!=0) f3=1;
		}
		if(n==2) solve1();
		else if(f2==0&&f3==0) solve2();
		//else if(f3==0) solve3();
		else solve();
	}
	return 0;
}
