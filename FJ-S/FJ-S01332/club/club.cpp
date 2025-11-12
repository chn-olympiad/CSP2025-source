//16:48 killed,WC is very good,let my brain rotate
//check 10w group can BOOM I eat.18:02
#include<iostream>
#include<stdio.h>
#include<algorithm>
#define int long long//isn't UB()
using namespace std;
const int N=2e5+1;
int T,n;
struct peo{
	int a,b;
	int c1,c2;
}r[N];
bool cmp1(pair<int,int>x,pair<int,int>y){
	return x.first>y.first;
}
bool cmp2(peo x,peo y){
	return x.a>y.a;
}
bool cmp3(peo x,peo y){
	return x.a-x.b<y.a-y.b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);//remember to change lld
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			pair<int,int>b[4];
			scanf("%lld%lld%lld",&b[1].first,&b[2].first,&b[3].first);
			b[1].second=1,b[2].second=2,b[3].second=3;
			sort(b+1,b+4,cmp1);
			r[i].a=b[1].first,r[i].b=b[2].first;
			r[i].c1=b[1].second,r[i].c2=b[2].second;
		}
		//直接取 
		sort(r+1,r+1+n,cmp2);
		int ans=0,c[4];
		c[1]=c[2]=c[3]=0;
		for(int i=1;i<=n;i++){
			ans+=r[i].a;
			c[r[i].c1]++;
		}
		//对多的进行去除 
		int del=max(max(c[1],c[2]),c[3]);
		for(int i=1;i<=n;i++){
			if(c[1]==del&&r[i].c1!=1)r[i].a=1e12,r[i].b=-1e12;
			if(c[2]==del&&r[i].c1!=2)r[i].a=1e12,r[i].b=-1e12;
			if(c[3]==del&&r[i].c1!=3)r[i].a=1e12,r[i].b=-1e12;
		}
		sort(r+1,r+1+n,cmp3);
		for(int i=1;i<=del-n/2;i++){
			ans=ans-r[i].a+r[i].b;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
#include<iostream>
#include<stdio.h>
using namespace std;
int T,n,ans,finallans,fflag;
int a[31][4];
void dfs(int x,int c1,int c2,int c3,bool flag){
	if(x==n+1){
		if(ans>finallans){
			fflag=flag;
		}
		finallans=max(finallans,ans);
		return;
	}
	if(c1+1<=n/2){
		bool cop=flag;
		if(a[x][1]<a[x][2]&&a[x][1]<a[x][3])flag=1;
		ans+=a[x][1];
		dfs(x+1,c1+1,c2,c3,flag);
		ans-=a[x][1];
		flag=cop;
	}
	if(c2+1<=n/2){
		bool cop=flag;
		if(a[x][2]<a[x][1]&&a[x][2]<a[x][3])flag=1;
		ans+=a[x][2];
		dfs(x+1,c1,c2+1,c3,flag);
		ans-=a[x][2];
		flag=cop;
	}
	if(c3+1<=n/2){
		bool cop=flag;
		if(a[x][3]<a[x][1]&&a[x][3]<a[x][2])flag=1;
		ans+=a[x][3];
		dfs(x+1,c1,c2,c3+1,flag);
		ans-=a[x][3];
		flag=cop;
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		finallans=ans=0;
		dfs(1,0,0,0,0);
		cout<<finallans<<endl;
	}
	return 0;
}
#include<iostream>
using namespace std;
int main(){
	for(int i=1;i<=1e5;i++){
		cout<<"#"<<i<<'\n';
		system("make.exe>out.txt");
		system("club.exe<out.txt>c.txt");
		system("force.exe<out.txt>f.txt");
		if(system("fc c.txt f.txt"))return 0;
	}
	return 0;
}
#include<iostream>
#include<time.h>
using namespace std;
int rd(int l,int r){
	return l+rand()%(r-l+1);
}
int main(){
	srand(time(0));
	int q=rd(5,10);
	cout<<q<<endl;
	for(int i=1;i<=q;i++){
		int n=rd(3,8)*2;
		cout<<n<<endl;
		for(int j=1;j<=n;j++){
			cout<<rd(0,2e4)<<' '<<rd(0,2e4)<<' '<<rd(0,2e4)<<endl;
		}
	}
	return 0;
}
*/
