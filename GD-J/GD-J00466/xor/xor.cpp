#include<bits/stdc++.h>
using namespace std;
const int INF=500000;
int a[INF+5],n,k,sum[INF+5],cnt=0,ans=1,ed;
struct line{
	int l,r;
}p[INF+5];
bool cmp(line& x,line& y){
	if(x.r!=y.r){
		return x.r<y.r;
	}
	else{
		return x.l>y.l;
	}
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
}
sum[1]=a[1];
for(int i=2;i<=n;i++){
	sum[i]=sum[i-1]^a[i];
	
}
for(int i=1;i<=n;i++){
	if(a[i]==k){
		p[++cnt].l=i;
		p[cnt].r=i;
	}
	if(sum[i]==k){
		p[++cnt].l=1;
		p[cnt].r=i;
	}
	
}
for(int i=3;i<=n;i++){
	for(int j=1;j+1<i;j++){
		
		if((sum[i]^sum[j])==k){
			p[++cnt].l=j+1;
			p[cnt].r=i;
		
		}
	}
}
if(cnt==0){
	cout<<0;
	return 0;
}
sort(p+1,p+cnt+1,cmp);

ed=p[1].r;
for(int i=1;i<=cnt;i++){
	if(p[i].l>ed){
		ans++;
		ed=p[i].r;
		
	}
}
cout<<ans;
fclose(stdin);
fclose(stdout); 
return 0;
}
