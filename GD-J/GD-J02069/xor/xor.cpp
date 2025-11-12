#include<bits/stdc++.h>
using namespace std;
int n,k,m,t,ans,a[500005],s[500005],bz[500005];
struct node{int x,y,z;}b[500005];
int cmp(node x,node y){
	if(x.z==y.z) return x.x<y.x;
	return x.z<y.z;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
		if(a[i]==0) t=1;
		if(a[i]>1) t=2;
	}
	if(!t) return printf("%d",n/2),0;
	if(t==1){
		if(!k){
			for(int i=1;i<=n;i++){
				if(!a[i]) ans++;
				else if(a[i]==a[i+1]&&a[i]&&i<n) ans++,i++;
			}
		}
		else{
			for(int i=1;i<=n;i++) if(a[i]) ans++;
		}
		return printf("%d",ans),0;
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++) if((s[j]^s[i-1])==k){b[i].y=j;break;}
		b[i].z=b[i].y-i,b[i].x=i;
		if(!b[i].y) b[i].z=INT_MAX;
	}
	sort(b+1,b+n,cmp);
	for(int i=1;i<n&&b[i].z<=n;i++){
		int t=0;
		for(int j=b[i].x;j<=b[i].y;j++)
			if(bz[j]){
				t=1;
				break;
			}
		if(!t){
			ans++;
			for(int j=b[i].x;j<=b[i].y;j++) bz[j]=1;
		}
	}
	printf("%d",ans);
	return 0;
}
