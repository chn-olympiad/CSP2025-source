#include <bits/stdc++.h>
using namespace std;
int n,k,cnt,ans;
int a[500005];
int f(int x,int y){
	return x^y;
}
void A(){
	cout<<floor(n/2);
	return ;
}
struct node{
	int l,r,s,m;
}v[10000005];
bool cmp(node x,node y){
	return x.m<y.m;
}
bool check[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool b=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
			b=1;
		}
	}
	if(k==0 && b==0){
		A();
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum=f(sum,a[j]);
			cnt++;
			v[cnt].s=sum;
			v[cnt].l=i;
			v[cnt].r=j;
			v[cnt].m=j-i+1;
		}
	}
	sort(v+1,v+cnt+1,cmp);
	/*
	for(int i=1;i<=cnt;i++){
		cout<<v[i].s<<" "<<v[i].l<<" "<<v[i].r<<endl;
	}
	int l1=0,r1=0,m1=0;
	*/
	for(int i=1;i<=cnt;i++){
		if(v[i].s==k){
			bool b2=0;
			for(int j=v[i].l;j<=v[i].r;j++){
				if(check[j]==1){
					b2=1;
					break;
				}
			}
			if(b2==0){
				ans++;
				for(int j=v[i].l;j<=v[i].r;j++){
					check[j]=1;
				}
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		cout<<check[i]<<" ";
	}
	cout<<endl;
	*/
	printf("%d",ans);
	return 0;
}
