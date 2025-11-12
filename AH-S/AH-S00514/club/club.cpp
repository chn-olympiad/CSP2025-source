#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=1e5+10;
ll t,n,cnt[4],ans;
struct node{
	ll a[4],f,id,s;
}c[N];
bool cmp(node a,node b){
	return a.s>b.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			c[i].a[1]=read();
			c[i].a[2]=read();
			c[i].a[3]=read();
			if(c[i].a[1]>c[i].a[2]&&c[i].a[1]>c[i].a[3]){
				c[i].f=c[i].a[1];
				c[i].id=1;
				c[i].s=c[i].f-max(c[i].a[2],c[i].a[3]);
			}
			else if(c[i].a[2]>c[i].a[3]){
				c[i].f=c[i].a[2];
				c[i].id=2;
				c[i].s=c[i].f-max(c[i].a[1],c[i].a[3]);
			}
			else{
				c[i].f=c[i].a[3];
				c[i].id=3;
				c[i].s=c[i].f-max(c[i].a[1],c[i].a[2]);
			}
		}
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[c[i].id]<n/2){
				ans+=c[i].f;
				cnt[c[i].id]++;
			}
			else{
				for(int j=i;j<=n;j++){
					c[j].f=0;
					for(int k=1;k<=3;k++){
						if(cnt[k]>=n/2)continue;
						if(c[j].f!=0)c[j].s=abs(c[j].a[k]-c[j].f);
						if(c[j].a[k]>c[j].f)
						{
							c[j].f=c[j].a[k];
							c[j].id=k;
						}
					}
				}
				sort(c+i+1,c+n+1,cmp);
				ans+=c[i].f;
				cnt[c[i].id]++;
			}
		}
		write(ans);
		puts("");
	}
	return 0;
}
