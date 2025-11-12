#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define ull unsigned long long
using namespace std;
char c[5000005],cc[5000005];
bool ck[5000005],fr[5000005];
ll ans;
int n,m,k,z,x,s,q;
char p[5000005];
struct node{
	ull a,b;
	int cnt;
}a[200005],b[200005],ha;
ull o,h;
void read(int &x){
	char ch=getchar();
	x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return ;
}
bool operator <(node aa,node bb){
	if(aa.a!=bb.a) return (aa.a<bb.a);
	return (aa.b<bb.b);
}
bool operator ==(node aa,node bb){
	return ((aa.a==bb.a)&(aa.b==bb.b));
}
int get(node aa){
	int l=1,r=n,mid;
	int s=0;
	while(l<=r){
		mid=(l+r)/2;
		if(b[mid]<aa){
			s=mid,l=mid+1;
		}
		else{
			if(r==mid) break;
			r=mid;
		}
	}
	return s;
}
int main(){
	//replace
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n),read(q);
	for(int i=1;i<=n;i++){
		scanf("%s",p);
		s=strlen(p);
		a[i].a=0;
		for(int j=0;j<s;j++) a[i].a=a[i].a*29+p[j]-'a'+1;
		scanf("%s",p);
		a[i].b=0;
		for(int j=0;j<s;j++) a[i].b=a[i].b*29+p[j]-'a'+1;
	}
	sort(a+1,a+n+1);
	int lt=1;
	b[1]=a[1],b[1].cnt=1;
	for(int i=2;i<=n;i++){
		if(b[lt].a!=a[i].a||b[lt].b!=a[i].b)
			++lt,b[lt]=a[i],b[lt].cnt=0;
		b[lt].cnt++;
	}
	n=lt;
	while(q--){
		scanf("%s %s",c,cc);
		m=strlen(c);
		for(int i=0;i<m;i++){
			if(c[i]==cc[i]) ck[i]=1;
			else ck[i]=0;
			if(i>0) ck[i]&=ck[i-1];
		}
		for(int i=m-1;i>=0;i--){
			if(c[i]==cc[i]) fr[i]=1;
			else fr[i]=0;
			if(i<m-1) fr[i]&=fr[i+1];
		}
		o=0,h=0,ans=0;
		for(int l=0;l<m;l++){
			if(l>0&&ck[l-1]==0) break;
			o=0,h=0;
			for(int r=l;r<m;r++){
				o=o*29+c[r]-'a'+1;
				h=h*29+cc[r]-'a'+1;
				if(r<m-1&&fr[r+1]==0) continue;
				ha.a=o,ha.b=h;
				x=get(ha);
				if(x<n&&b[x+1]==ha){
					ans+=b[x+1].cnt;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
