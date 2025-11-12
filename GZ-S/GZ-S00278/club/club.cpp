//GZ-S00278 毕节市七星关东辰实验学校 杨鹏鸣 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c;
}a[N] ;
long long n,t;
bool cmp(node a,node b){
	return a.a>b.a;
}
bool cmp1(node a,node b){
	return a.b>b.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0,cnt=0,cnt1=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b==0) cnt++;
			if(a[i].c==0) cnt1++;
		}
		if(cnt!=n&&cnt1==n){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=a[i].b;
			}
			cout<<ans<<endl;
			continue;
		}
		if(cnt==n){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans<<endl;
			continue;
		}	
		for(int i=1;i<=n;i++){
			ans+=max(max(a[i].a,a[i].b),a[i].c);
		}
		cout<<ans<<endl;
	}
	return 0;
}
