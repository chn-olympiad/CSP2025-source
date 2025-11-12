#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e6+10;
ll n,q,len1,len2,inv,ans;
char s[N],c[N];
struct STU{
	ull x,y;
	ll len;
}a[N];
ull ksm(ull x,ll y){
	ull ans=1;
	while(y){
		if(y&1)ans=ans*x;
		x=x*x;
		y>>=1;
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		scanf("%s",c+1);
		len1=strlen(s+1);
		a[i].len=len1;
		ull a1=0,a2=0;
		for(int i=1;i<=len1;i++){
			a1=(a1*131)+(s[i]-'a');
			a2=(a2*131)+(c[i]-'a');
//			cout<<i<<":"<<a1<<' '<<a2<<endl;
		}
		a[i].x=a1,a[i].y=a2;
//		cout<<a[i].x<<" "<<a[i].y<<endl;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		scanf("%s",s+1);
		scanf("%s",c+1);
		len1=strlen(s+1);
		len2=strlen(c+1);
		if(len1!=len2){
			puts("0");
			continue;
		}
		ll l=0,r=0;
		for(int j=1;j<=len1;j++){
			if(s[j]!=c[j]){
				if(!l)l=j;
				r=j;
			}
		}
		for(int j=1;j<=n;j++){
			ull p1=0,p2=0;
			if(r-a[j].len+1>l)continue;
			ll tr=r;
			while(tr-a[j].len+1<=0)tr++;
			for(int k=tr-a[j].len+1;k<=tr;k++){
				p1=p1*131+(s[k]-'a');
				p2=p2*131+(c[k]-'a');
//				cout<<k<<":"<<p1<<' '<<p2<<endl;
			}
			ull inv=ksm((ull)131,a[j].len);
			for(int y=tr,x=tr-a[j].len+1;y<=len1&&x<=l;y++,x++){
				if(y>tr){
					p1=(p1-inv*(s[x-1]-'a'))*131+(s[y]-'a');
					p2=(p2+inv*(c[x-1]-'a'))*131+(c[y]-'a');
				}
//				cout<<i<<":"<<x<<" "<<y<<" "<<p1<<" "<<p2<<endl;
				if(a[j].x==p1&&a[j].y==p2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3 1
aab acb
aa ac
a c
aaba acba
*/
