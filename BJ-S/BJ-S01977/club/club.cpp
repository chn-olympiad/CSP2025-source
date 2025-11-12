#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int a,b,c,cha1,cha2,ma,mid,mi;
	void solve(){
		if(max(a,max(b,c))==a){
			ma=1;
			cha1=a-max(b,c);
			if(b>c){
				cha2=b-c;
				mid=2;
				mi=3;
			}
			else{
				cha2=c-b;
				mid=3;
				mi=2;
			}
		}
		if(max(a,max(b,c))==b){
			ma=2;
			cha1=b-max(a,c);
			if(a>c){
				cha2=a-c;
				mid=1;
				mi=3;
			}
			else{
				cha2=c-a;
				mid=3;
				mi=1;
			}
		}
		if(max(a,max(b,c))==c){
			ma=3;
			cha1=c-max(a,b);
			if(a>b){
				cha2=a-b;
				mid=2;
				mi=3;
			}
			else{
				cha2=b-a;
				mid=3;
				mi=2;
			}
		}
	}
}a[100010];
bool cmp(node p1,node p2){
	if(p1.cha1!=p2.cha1){
		return p1.cha1>p2.cha1;
	}
	return p1.cha2>p2.cha2;
}
long long ans[10],num[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=5;i++){
			ans[i]=num[i]=0;
		}
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			a[i].solve();
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(num[a[i].ma]<n/2){
				num[a[i].ma]++;
				if(a[i].ma==1){
					ans[a[i].ma]+=a[i].a;
				}
				if(a[i].ma==2){
					ans[a[i].ma]+=a[i].b;
				}
				if(a[i].ma==3){
					ans[a[i].ma]+=a[i].c;
				}
			}
			else if(num[a[i].mid]<n/2){
				num[a[i].mid]++;
				if(a[i].mid==1){
					ans[a[i].mid]+=a[i].a;
				}
				if(a[i].mid==2){
					ans[a[i].mid]+=a[i].b;
				}
				if(a[i].mid==3){
					ans[a[i].mid]+=a[i].c;
				}
			}
			else{
				num[a[i].mi]++;
				if(a[i].mi==1){
					ans[a[i].mi]+=a[i].a;
				}
				if(a[i].mi==2){
					ans[a[i].mi]+=a[i].b;
				}
				if(a[i].mi==3){
					ans[a[i].mi]+=a[i].c;
				}
			}
		}
		cout<<ans[1]+ans[2]+ans[3]<<"\n";
	}
}
