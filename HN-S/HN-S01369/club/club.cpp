#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t,n,sum;
struct node{
	int jo[4];
	int cl[4];
	int dx;
	int zc;
	int sum;
}a[3*N];
long long ans;
node x[N],y[N],z[N];int cnt[4];
bool cmp(node le,node ri){
	return le.jo[le.dx]>ri.jo[le.dx];
}
bool cnp(node le,node ri){
	return le.zc<ri.zc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i =1;i<=t;i++){
		ans = 0;
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
		memset(z,0,sizeof z);
		cnt[1] = cnt[2] = cnt[3] = 0;  
		cin>>n;
		for(int j = 1;j<=n;j++){
			cin>>a[j].jo[1]>>a[j].jo[2]>>a[j].jo[3];
			a[1].cl[1] = 1;a[1].cl[2] = 2;a[1].cl[3] = 3;
			if(a[j].jo[1]>a[j].jo[2]){
				a[j].dx = 1;
				sum = 2;
			}
			else{
				sum = 1;
				a[j].dx = 2;
			}
			if(a[j].jo[3]>a[j].jo[a[j].dx]){
				
				a[j].dx = 3;
			}
			else{
				if(a[j].jo[3]>a[j].jo[sum]){
					sum = 3;
				}
			}
			a[j].zc = a[j].jo[a[j].dx]-a[j].jo[sum];
			a[j].sum = sum;
		}
		sort(a+1,a+1+n,cmp);
		for(int j = 1;j<=n;j++){
			if(a[j].dx==1){
				x[++cnt[1]] = a[j];
			}
			if(a[j].dx==2){
				y[++cnt[2]] = a[j];
			}
			if(a[j].dx==3){
				
				z[++cnt[3]] = a[j];
			}
		}
		if(cnt[1]>n/2){
			sort(x+1,x+1+cnt[1],cnp);
			for(int j = 1;j<=cnt[1]-n/2;j++){
				ans+=x[j].jo[x[j].sum];
			}
			for(int j = cnt[1]-n/2+1;j<=cnt[1];j++){
				ans+=x[j].jo[x[j].dx];
			}
		}
		else{
			for(int j = 1;j<=cnt[1];j++){
				ans+=x[j].jo[x[j].dx];
			}
		}
		if(cnt[2]>n/2){
			sort(y+1,y+1+cnt[2],cnp);
			for(int j = 1;j<=cnt[2]-n/2;j++){
				ans+=y[j].jo[y[j].sum];
			}
			for(int j = cnt[2]-n/2+1;j<=cnt[2];j++){
				ans+=y[j].jo[y[j].dx];
			}
		}
		else{
			for(int j = 1;j<=cnt[2];j++){
				ans+=y[j].jo[y[j].dx];
			}
		}
		if(cnt[3]>n/2){
			sort(z+1,z+1+cnt[3],cnp);
			for(int j = 1;j<=cnt[3]-n/2;j++){
				ans+=z[j].jo[z[j].sum];
			}
			for(int j = cnt[3]-n/2+1;j<=cnt[3];j++){
				ans+=z[j].jo[z[j].dx];
			}
		}
		else{
			for(int j = 1;j<=cnt[3];j++){
				ans+=z[j].jo[z[j].dx];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
