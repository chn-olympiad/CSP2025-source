#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],b[N],c[N];
int vis[N];
priority_queue<pair<int,int> >qb;
priority_queue<pair<int,int> >qc;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!('0'<=c&&c<='9')){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x;
}
void w(){
	while(qb.size()!=0)qb.pop();
	while(qc.size()!=0)qc.pop();
	n=read();
	int ans=0,B=0,C=0,A=n;
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read(),c[i]=read();
		vis[i]=1;
		ans+=a[i];
		qb.push({b[i]-a[i],i});
		qc.push({c[i]-a[i],i});
	}
//	cout<<ans<<"\n";
	for(int i=1;i<=n;i++){
		while(qb.size()&&vis[qb.top().second]!=1)qb.pop();
		while(qc.size()&&vis[qc.top().second]!=1)qc.pop();
		int x=qb.top().first,X=qb.top().second,y=qc.top().first,Y=qc.top().second;
		if(x<0&&y<0&&A<=n/2)break;
//		cout<<x<<" "<<X<<" "<<y<<" "<<Y<<"\n";
		A--;
		if(x>y){
			qb.pop();
			B++; 
			vis[X]=2;
			ans+=x;
		}
		else{
			qc.pop();
			vis[Y]=3;
			C++;
			ans+=y;
		}
	}
	while(qb.size()!=0)qb.pop();
	while(qc.size()!=0)qc.pop();
	if(B>n/2){
		for(int i=1;i<=n;i++){
			if(vis[i]==2){
				qb.push({a[i]-b[i],i});
				qc.push({c[i]-b[i],i});
			}
		}
		for(int i=1;i<=n;i++){
			while(qb.size()&&vis[qb.top().second]!=2)qb.pop();
			while(qc.size()&&vis[qc.top().second]!=2)qc.pop();
			int x=qb.top().first,X=qb.top().second,y=qc.top().first,Y=qc.top().second;
			if(x<0&&y<0&&B<=n/2)break;
	//		cout<<x<<" "<<X<<" "<<y<<" "<<Y<<"\n";
			B--;
			if(x>y){
				qb.pop();
				A++; 
				vis[X]=1;
				ans+=x;
			}
			else{
				qc.pop();
				vis[Y]=3;
				C++;
				ans+=y;
			}
		}
	}
	while(qb.size()!=0)qb.pop();
	while(qc.size()!=0)qc.pop();
	if(C>n/2){
		for(int i=1;i<=n;i++){
			if(vis[i]==3){
				qb.push({a[i]-c[i],i});
				qc.push({b[i]-c[i],i});
			}
		}
		for(int i=1;i<=n;i++){
			while(qb.size()&&vis[qb.top().second]!=3)qb.pop();
			while(qc.size()&&vis[qc.top().second]!=3)qc.pop();
			int x=qb.top().first,X=qb.top().second,y=qc.top().first,Y=qc.top().second;
			if(x<0&&y<0&&C<=n/2)break;
	//		cout<<x<<" "<<X<<" "<<y<<" "<<Y<<"\n";
			C--;
			if(x>y){
				qb.pop();
				A++; 
				vis[X]=1;
				ans+=x;
			}
			else{
				qc.pop();
				vis[Y]=2;
				B++;
				ans+=y;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)w();
	return 0;
}

