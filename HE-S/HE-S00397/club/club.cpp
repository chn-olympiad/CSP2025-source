#include<bits/stdc++.h>
using namespace std;
int n;
int t;
struct man{
	int bumen;
	int a;
	int id;
};
man a[300010];
bool cmp(man a,man b){
	return a.a>b.a;
}
bool ren[100010];
int sum[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		int cnt=0;
		for(int i=0;i<100010;i++) {
			a[i].a=0;
			a[i].bumen=0;
			a[i].id=0;
			ren[i]=0;
		}
		for(int i=0;i<10;i++) {
			sum[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[++cnt].a=x;
			a[cnt].bumen=1;
			a[cnt].id=i;
			
			a[++cnt].a=y;
			a[cnt].bumen=2;
			a[cnt].id=i;
			
			a[++cnt].a=z;
			a[cnt].bumen=3;
			a[cnt].id=i;
		}
		sort(a+1,a+n*3+1,cmp);
		//for(int i=1;i<=cnt;i++) cout<<a[i].a<<' '<<a[i].bumen<<a[i].id<<endl;
		for(int i=1;i<=cnt;i++){
			if(sum[a[i].bumen]+1<=(n/2)&&ren[a[i].id]==0){
				sum[a[i].bumen]+=1;
				ren[a[i].id]=1;
				ans+=a[i].a;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
