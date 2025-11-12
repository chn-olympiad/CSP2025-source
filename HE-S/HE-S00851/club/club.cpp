#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,x,y,z;
struct zz{
	int m1,m2,s1,s2;
}b[110000];
int c[110000],top;
map<int,int> mp;
bool cmp(zz s1,zz s2){
	return s1.m1>s2.m1;
}bool cmp1(int s1,int s2){
	return s1>s2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		mp.clear();
		cin>>n;
		int ans=0,top=0;
		int x,y,z;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				b[i].m1=x;
				b[i].m2=max(y,z);
				b[i].s1=1;
				if(b[i].m2==y)b[i].s2=2;
				else b[i].s2=3;
			}else if(y>=x&&y>=z){
				b[i].m1=y;b[i].m2=max(x,z);
				b[i].s1=2;
				if(b[i].m2==x)b[i].s2=1;
				else b[i].s2=3;	
			}else{
				b[i].m1=z;b[i].m2=max(x,y);
				b[i].s1=3;
				if(b[i].m2==x)b[i].s2=1;
				else b[i].s2=2;
			}
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n;i++){
			cout<<b[i].m1<<" "<<b[i].s1<<' ';
			cout<<b[i].m2<<" "<<b[i].s2<<endl;
		}
		int biao=0,sum=n/2,num=0,now;
		for(int i=1;i<=n;i++){
			if(mp[b[i].s1]<sum){
				mp[b[i].s1]++;
				ans+=b[i].m1;
			}else{
				now=b[i].s1;
				ans+=b[i].m2;
			}
		}for(int i=1;i<=n;i++){
			if(b[i].s1==now){
				if(num<n/2)c[++top]=b[i].m2-b[i].m1,num++;	
				else c[++top]=b[i].m1-b[i].m2,num++;
			}
		}
		sort(c+1,c+1+top,cmp1);
		cout<<ans<<endl;
		int sum1=top-n/2+1;
		cout<<sum1<<endl;
		for(int i=1;i<=top;i++){
			if(c[i]+c[sum1]>0)ans+=c[i]+c[sum1],++sum1;
			else break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
