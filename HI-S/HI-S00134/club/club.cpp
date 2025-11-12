#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,t,ans;
long long a1,a2,a3;
struct point{
	int a,b,c;
}a[N];
bool cmpA(point a,point b){
	return a.a>b.a;
}
bool cmpB(point a,point b){
	return a.b>b.b;
}
bool cmpC(point a,point b){
	return a.c>b.c;
}
int main(){//如果采用dp，则需要编写特殊的排序 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		a1=0;a2=0;a3=0;ans=0;memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a1+=a[i].a;a2+=a[i].b;a3+=a[i].c;
		}if(a3==0&&a2==0){
			sort(a+1,a+1+n,cmpA);
			for(int i=1;i<=n/2;i++) ans+=a[i].a;
		}else if(a1==0&&a2==0){
			sort(a+1,a+1+n,cmpC);
			for(int i=1;i<=n/2;i++) ans+=a[i].c;
		}else if(a3==0&&a1==0){
			sort(a+1,a+1+n,cmpB);
			for(int i=1;i<=n/2;i++) ans+=a[i].b;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
