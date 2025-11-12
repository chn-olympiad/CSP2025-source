#include<bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
#define gc getchar()
void read(int &n){int l=1,num;char ch;
while(ch=gc,ch>'9'||ch<'0')if(ch=='-')l=-1;
num=ch-'0';while(ch=gc,ch<='9'&&ch>='0')
num=num*10+ch-'0';n=num*l;return;}

int n;
struct stu{int a,b,c,s;}a[N];
int a1[N],a2[N],a3[N],tot1,tot2,tot3;
bool cmp(int x,int y){
	if(a[x].s==1)return min(a[x].a-a[x].b,a[x].a-a[x].c)>min(a[y].a-a[y].b,a[y].a-a[y].c);
	if(a[x].s==2)return min(a[x].b-a[x].a,a[x].b-a[x].c)>min(a[y].b-a[y].a,a[y].b-a[y].c);
	if(a[x].s==3)return min(a[x].c-a[x].b,a[x].c-a[x].a)>min(a[y].c-a[y].b,a[y].c-a[y].a);
}
signed main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	int t;read(t);while(t--){
		read(n);for(int i=1;i<=n;i++)read(a[i].a),read(a[i].b),read(a[i].c);
		for(int i=1;i<=n;i++)a1[i]=a2[i]=a3[i]=tot1=tot2=tot3=0;
		for(int i=1;i<=n;i++){
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){a[i].s=1;a1[++tot1]=i;}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){a[i].s=2;a2[++tot2]=i;}
			else{a[i].s=3;a3[++tot3]=i;}
		}
		sort(a1+1,a1+tot1+1,cmp);sort(a2+1,a2+tot2+1,cmp);sort(a3+1,a3+tot3+1,cmp);
		while(tot1>n/2){if(a[a1[tot1]].b>a[a1[tot1]].c)a[a1[tot1]].s=2,a2[++tot2]=a1[tot1];
		else a[a1[tot1]].s=3,a3[++tot3]=a1[tot1];tot1--;}
		while(tot2>n/2){if(a[a2[tot2]].a>a[a2[tot2]].c)a[a2[tot2]].s=1,a1[++tot1]=a2[tot2];
		else a[a2[tot2]].s=3,a3[++tot3]=a2[tot2];tot2--;}
		while(tot3>n/2){if(a[a3[tot3]].b>a[a3[tot3]].a)a[a3[tot3]].s=2,a2[++tot2]=a3[tot3];
		else a[a3[tot3]].s=1,a1[++tot1]=a3[tot3];tot3--;}
		int ans=0;for(int i=1;i<=n;i++){
			if(a[i].s==1)ans+=a[i].a;
			if(a[i].s==2)ans+=a[i].b;
			if(a[i].s==3)ans+=a[i].c;
		}cout<<ans<<endl;
	}
	return 0;
}
