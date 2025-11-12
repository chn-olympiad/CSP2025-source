#include<bits/stdc++.h>
using namespace std;
int t,n;
struct l{
	int id,z;
}k[10];
struct node{
	int m1,m2;
	int id1,id2;
}x[100005];
bool cmp(node x,node y){
	return x.m1-x.m2>y.m1-y.m2;
}
bool cmp1(l a,l b){
	return a.z>b.z;
}
int a[10],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>k[j].z;
				k[j].id=j;
			}
			sort(k+1,k+4,cmp1);
			x[i].m1=k[1].z;
			x[i].m2=k[2].z;
			x[i].id1=k[1].id;
			x[i].id2=k[2].id;
		}
		sort(x+1,x+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[x[i].id1]<n/2){
				a[x[i].id1]++;
				ans+=x[i].m1;
			}else{
				a[x[i].id2]++;
				ans+=x[i].m2;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
