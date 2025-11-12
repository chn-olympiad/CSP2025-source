#include<bits/stdc++.h>
using namespace std;
#define N 1000005
struct node{
	int a,b,c;
}f[N];
struct Node{
	int a,b;
}k[N];
bool cmp(node x,node y){
	if(x.a==y.a){
		if(x.b==y.b){
			return x.c>y.c;
		}
		return x.b>y.b;
	}
	return x.a>y.a;
}
bool cmpp(Node x,Node y){
	if(x.b==y.b){
		return x.a>y.a;
	}
	return x.b<y.b;
}
void solve(){
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
	}
	sort(f+1,f+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(f[i].a>f[i].b&&f[i].a>f[i].c){
			k[i]={i,1};
		}
		if(f[i].a<f[i].b&&f[i].c<f[i].b){
			k[i]={i,2};
		} 
		if(f[i].a<f[i].c&&f[i].b<f[i].c){
			k[i]={i,3};
		}
	}
	sort(k+1,k+n+1,cmpp);
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		if(k[i].b==1) cnt1++;
		if(k[i].b==2) cnt2++;
		if(k[i].b==3) cnt3++;
	}
//	cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<'\n';
	if(cnt1>(n/2)){
		int i=1,j=1;
		while(1){
			if(f[k[n/2+j].a].a-max(f[k[n/2+j].a].b,f[k[n/2+j].a].c)>f[k[i].a].a-max(f[k[i].a].b,f[k[i].a].c)){
				if(f[k[i].a].b>f[k[i].a].c){
					k[i].b=2;cnt2++;
				}
				else{
					k[i].b=3;cnt3++;
				}
				i++;
			}
			else{
				if(f[k[n/2+j].a].b>f[k[n/2+j].a].c){
					k[n/2+j].b=2;cnt2++;
				}
				else {
					k[n/2+j].b=3;cnt3++;
				}
				j++;
			}
			cnt1--;
			if(cnt1==n/2) break;
		}
	}
	if(cnt2>(n/2)){
		int i=1,j=1;
		while(1){
			if(f[k[n/2+j].a].b-max(f[k[n/2+j].a].a,f[k[n/2+j].a].c)>f[k[i].a].b-max(f[k[i].a].a,f[k[i].a].c)){
				if(f[k[i].a].a>f[k[i].a].c&&cnt1<n/2){
					k[i].b=1;cnt1++;
				}
				else{
					k[i].b=3;cnt3++;
				}
				i++;
			}
			else{
				if(f[k[n/2+j].a].a>f[k[n/2+j].a].c&&cnt1<n/2){
					k[n/2+j].b=1;cnt1++;
				}
				else{
					k[n/2+j].b=3;cnt3++;
				}
			}
			cnt2--;
			if(cnt2==n/2) break;
		}
	}
	if(cnt3>(n/2)){
		int i=1,j=1;
		while(1){
			if(f[k[n/2+j].a].c-max(f[k[n/2+j].a].a,f[k[n/2+j].a].b)>f[k[i].a].c-max(f[k[i].a].a,f[k[i].a].b)){
				if(f[k[i].a].a>f[k[i].a].b&&cnt1<n/2){
					k[i].b=1;cnt1++;
				}
				else{
					k[i].b=2;cnt2++;
				}
				i++;
			}
			else{
				if(f[k[n/2+j].a].a>f[k[n/2+j].a].b&&cnt1<n/2){
					k[i].b=1;cnt1++;
				}
				else{
					k[i].b=2;cnt2++;
				}
				j++;
			}
			cnt3--;
			if(cnt3==n/2) break;
		}
	}
	for(int i=1;i<=n;i++){
//		cout<<k[i].a<<" "<<k[i].b<<'\n';
		if(k[i].b==1){
//			cout<<f[k[i].a].a<<"\n";
			ans+=f[k[i].a].a;
		}
		if(k[i].b==2){
//			cout<<f[k[i].a].b<<"\n";
			ans+=f[k[i].a].b;
		}
		if(k[i].b==3){
//			cout<<f[k[i].a].c<<"\n";
			ans+=f[k[i].a].c;
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
} 
