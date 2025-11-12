#include<bits/stdc++.h>
#define max(a,b) a>b?a:b
using namespace std;
struct people{
	int a,b,c;
	int ch;
}a[100005],b[100005],c[100005];
bool cmp(people a,people b){
	return a.ch>b.ch;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=1;i<=n;++i){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(x>=y&&x>=z)a[++cnt1].a=x,a[cnt1].b=y,a[cnt1].c=z,ans+=x;
			else if(y>=x&&y>=z)b[++cnt2].a=x,b[cnt2].b=y,b[cnt2].c=z,ans+=y;
			else c[++cnt3].a=x,c[cnt3].b=y,c[cnt3].c=z,ans+=z; 
		}
		if(cnt1>n/2){
			for(int i=1;i<=cnt1;++i)a[i].ch=max(a[i].b-a[i].a,a[i].c-a[i].a);
			sort(a+1,a+cnt1+1,cmp);
			for(int i=1;i<=cnt1-n/2;++i)ans+=a[i].ch;
		}
		if(cnt2>n/2){
			for(int i=1;i<=cnt2;++i)b[i].ch=max(b[i].c-b[i].b,b[i].a-b[i].b);
			sort(b+1,b+cnt2+1,cmp);
			for(int i=1;i<=cnt2-n/2;++i)ans+=b[i].ch;
		}
		if(cnt3>n/2){
			for(int i=1;i<=cnt3;++i)c[i].ch=max(c[i].b-c[i].c,c[i].a-c[i].c);
			sort(c+1,c+cnt3+1,cmp);
			for(int i=1;i<=cnt3-n/2;++i)ans+=c[i].ch;
		}
		cout<<ans<<endl;
	}
	return 0;
}
