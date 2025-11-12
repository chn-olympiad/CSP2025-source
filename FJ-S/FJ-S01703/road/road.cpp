#include<bits/stdc++.h>
using namespace std;
struct h{
	int l,r,v;
}a[1100005];
int n,m,k,b[15],v1[10005];
long long s,d,f,g;
bool cmp(h z,h x){
	return z.v<x.v;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; 
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].v);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i]);
		if(b[i]==0){
			d++;
		}
		for(int j=1;j<=n;j++){
			scanf("%d",&a[j+i*m].v);
			a[j+i*m].r=j;
		}
	}
	if(k==0){
		for(int i=1;i<=n*k+m;i++){
			if((a[i].l!=0&&v1[a[i].l]==0)||(v1[a[i].r]==0&&a[i].r!=0)){
				s+=a[i].v;
				f++;
				if(v1[a[i].l]==0){
					if(a[i].l!=0) d--;
					v1[a[i].l]=1;
				}
				if(v1[a[i].r]==0){
					if(a[i].r!=0) d--;
					v1[a[i].r]=1;
				}
			}
			if(d<=0&&f==n-1){
				cout<<s;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
		cout<<s;
	}else if(d==k){
		d=n;
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			if((a[i].l!=0&&v1[a[i].l]==0)||(v1[a[i].r]==0&&a[i].r!=0)){
				s+=a[i].v;
				f++;
				if(v1[a[i].l]==0){
					if(a[i].l!=0) d--;
					v1[a[i].l]=1;
				}
				if(v1[a[i].r]==0){
					if(a[i].r!=0) d--;
					v1[a[i].r]=1;
				}
			}
			if(d<=0&&f==n-1){
				g=s;
				break;
			}
		}
		s=0;
		for(int i=1;i<=n;i++){
			v1[i]=0;
		}
		f=0;
		d=n;
		sort(a+1,a+n*k+m+1,cmp);
		for(int i=1;i<=n*k+m;i++){
			if((a[i].l!=0&&v1[a[i].l]==0)||(v1[a[i].r]==0&&a[i].r!=0)){
				s+=a[i].v;
				f++;
				if(v1[a[i].l]==0){
					if(a[i].l!=0) d--;
					v1[a[i].l]=1;
				}
				if(v1[a[i].r]==0){
					if(a[i].r!=0) d--;
					v1[a[i].r]=1;
				}
			}
			if(d<=0&&f==n){
				cout<<min(s,g);
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
		cout<<s;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
