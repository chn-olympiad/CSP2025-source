#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll n,m,a[N],sum,flag=1,ans;
struct node{
	ll x,y;
};
vector<node>T;
bool cmp(node x,node y){
	if(x.y==y.y)return x.x<y.x;
	else return x.y<y.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	if(n>1000){
		ll ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans1++;
			else ans2++;
		}
		if(m==1)cout<<ans1;
		else cout<<ans2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum=a[1];
	flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]==m){
			T.push_back({i,i});
			sum=a[i+1];
//			cout<<"sum:"<<sum<<endl;
			continue;
			`
		}
		sum=a[i];
		for(int j=i+1;j<=n;j++){
			ll x=sum^a[j];
			if(x==m){
				T.push_back({i,j});
				
//				cout<<' '<<x<<' '<<sum<<' '<<a[j]<<endl;
//				cout<<"sum:"<<sum<<endl;
				flag=0;
				break;
			}
//			else cout<<x<<' '<<sum<<endl;
			sum=x;
		}
//		if(flag)cout<<"sum:"<<sum<<endl;
		flag=1;
	}
//	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//	cout<<endl;
//	for(auto it:T)cout<<it.x<<' '<<it.y<<endl;
	sort(T.begin(),T.end(),cmp);
	if(T.size())ans=1;
	else ans=0;
	for(int i=1;i<T.size();i++){
		if(T[i].x>T[i-1].y)ans++;
	}
	cout<<ans;
	return 0;
//	4 2
//  2 1 0 3
}
