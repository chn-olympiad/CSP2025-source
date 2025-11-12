#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct abc{
	int a,num;
};
bool good(abc a,abc b){
	return a.a>b.a;
}
int t,n,d[N];
abc a[N],b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int res=0,sum=0;
		cin>>n;
		int x=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>b[i].a>>c[i].a;
			a[i].num=b[i].num=c[i].num=i;
		}
		sort(a+1,a+1+n,good);
		sort(b+1,b+1+n,good);
		sort(c+1,c+1+n,good); 
		for(int j=1;j<=x;j++){
			sum+=a[j].a;
			d[a[j].num]=1;
		}
		for(int j=1;j<=x;j++){
			if(d[b[j].num]==0){
				sum+=b[j].a;
				d[b[j].num]=1;
			}
		}
		for(int j=1;j<=x;j++){
			if(d[c[j].num]==0){
				sum+=c[j].a;
				d[c[j].num]=1;
			}
		} 
		memset(d,0,sizeof d);
		res=max(res,sum);
		sum=0;
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(d[b[j].num]==0){
				sum+=b[j].a;
				d[b[j].num]=1;
				cnt++;
			}
			if(cnt==x) break;
		} 
		cnt=0;
		for(int j=1;j<=n;j++){
			if(d[a[j].num]==0){
				sum+=a[j].a;
				d[a[j].num]=1;
				cnt++;
			}
			if(cnt==x) break;
		} 
		cnt=0;
		for(int j=1;j<=n;j++){
			if(d[c[j].num]==0){
				sum+=c[j].a;
				d[c[j].num]=1;
				cnt++;
			}
			if(cnt==x) break;
		} 
		memset(d,0,sizeof d);
		res=max(res,sum);
		sum=0;
		cnt=0;
		for(int j=1;j<=n;j++){
			sum+=c[j].a;
			d[c[j].num]=1;
			cnt++;
			if(cnt==x) break;
		} 
		cnt=0;
		for(int j=1;j<=n;j++){
			if(d[a[j].num]==0){
				sum+=a[j].a;
				d[a[j].num]=1;
				cnt++;
			}
			if(cnt==x) break;
		} 
		cnt=0;
		for(int j=1;j<=n;j++){
			if(d[b[j].num]==0){
				sum+=b[j].a;
				d[b[j].num]=1;
				cnt++;
			}
			if(cnt==x) break;
		} 
		res=max(res,sum);
		cout<<res<<"\n";
	}
	return 0;
}
