#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][4],tag[N];
struct Node{
	int v;
	int id;
}x[N],y[N],z[N];
bool cmp(Node A,Node B){
	return A.v>B.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		cin>>n;
		int ans=0;
		int cnt1=0,cnt2=0,cnt3=0,bgkl=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			//x[i]=a[i][1],y[i]=a[i][2],z[i]=a[i][3];
			if(a[i][1]==max(max(a[i][1],a[i][2]),a[i][3])){
				x[++cnt1].v=a[i][1];
				x[cnt1].id=i;
			}
			else if(a[i][2]==max(max(a[i][1],a[i][2]),a[i][3])){
				y[++cnt2].v=a[i][2];
				y[cnt2].id=i;
			}
			else{
				z[++cnt3].v=a[i][3];
				z[cnt3].id=i;
			}
			if(a[i][2]||a[i][3]){
				bgkl=1;
			}						
		}
		sort(x+1,x+cnt1+1,cmp),sort(y+1,y+cnt2+1,cmp),sort(z+1,z+cnt3+1,cmp);
		if(bgkl==0){
			int dic=0;
			for(int i=1;i<=cnt1/2;i++){
				dic+=x[i].v;
			}
			cout<<dic<<"\n";
		}
		if(n==2){
			int uck=0;
			int dik;
			for(int i=1;i<=3;i++){
				dik=a[1][i];
				for(int j=1;j<=3;j++){
					if(i!=j){
						dik+=a[2][j];
					}
					uck=max(uck,dik);
					dik=a[1][i];
				}
			}
			cout<<uck<<"\n";
		}
		if(n!=2&&bgkl&&cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			for(int i=1;i<=cnt1;i++){
				ans+=x[i].v;
			}
			for(int i=1;i<=cnt2;i++){
				ans+=y[i].v;
			}
			for(int i=1;i<=cnt3;i++){
				ans+=z[i].v;
			}
			cout<<ans<<"\n";
		}else if(n!=2&&bgkl){
			if(cnt1>n/2){
				for(int i=n/2+1;i<=cnt1;i++){
					if(a[x[i].id][2]>a[x[i].id][3]){
						y[++cnt2].v=a[x[i].id][2];
						cnt1--;
					}else{
						z[++cnt3].v=a[x[i].id][3];
						cnt1--;
					}
				}
			}
			else if(n!=2&&bgkl&&cnt2>n/2){
				for(int i=n/2+1;i<=cnt2;i++){
					if(a[y[i].id][1]>a[y[i].id][3]){
						x[++cnt1].v=a[y[i].id][1];
						cnt2--;
					}else{
						z[++cnt3].v=a[y[i].id][3];
						cnt2--;
					}
				}
			}
			else if(bgkl&&n!=2){
				for(int i=n/2+1;i<=cnt3;i++){
					if(a[z[i].id][1]>a[z[i].id][3]){
						x[++cnt1].v=a[z[i].id][1];
						cnt3--;
					}else{
						y[++cnt2].v=a[z[i].id][2];
						cnt3--;
					}
				}				
			}
			for(int i=1;i<=cnt1;i++){
				ans+=x[i].v;
			}
			for(int i=1;i<=cnt2;i++){
				ans+=y[i].v;
			}
			for(int i=1;i<=cnt3;i++){
				ans+=z[i].v;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
