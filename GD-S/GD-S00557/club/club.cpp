#include<bits/stdc++.h>
using namespace std;
struct wendy{
	long long int x[4],y[4],z[4];
}a[100005];
inline bool qun(wendy m,wendy n){
	if(m.y[1]!=n.y[1])return m.y[1]>n.y[1];
	if(m.y[2]!=n.y[2])return m.y[2]>n.y[2];
	return m.y[3]>n.y[3];
}
void work(){
	 int n,g[10]={0};
	 long long int ans1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i].x[1],&a[i].x[2],&a[i].x[3]);
		for(int j=1;j<=3;j++)a[i].y[j]=a[i].x[j],a[i].z[j]=j;
		if(a[i].y[1]<a[i].y[2])swap(a[i].y[1],a[i].y[2]),swap(a[i].z[1],a[i].z[2]);
		if(a[i].y[2]<a[i].y[3])swap(a[i].y[2],a[i].y[3]),swap(a[i].z[2],a[i].z[3]);
		if(a[i].y[1]<a[i].y[2])swap(a[i].y[1],a[i].y[2]),swap(a[i].z[1],a[i].z[2]);
	}
	sort(a+1,a+1+n,qun);
//	for(int i=1;i<=n;i++)
//	printf("%d %d %d\n%d %d %d\n",a[i].y[1],a[i].y[2],a[i].y[3],a[i].z[1],a[i].z[2],a[i].z[3]);
//	printf("\n\n"); 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){	
		if(g[a[i].z[j]]<n/2){
			g[a[i].z[j]]++;
			ans1+=a[i].y[j];
			break;
		}
	}
	
	}cout<<ans1<<"\n\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cout<<"aiventi";
	int t;
	scanf("%d",&t);
	while(t--){
		work();
	}
	fclose(stdin);
	fclose(stdout);
} 
