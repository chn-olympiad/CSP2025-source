#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
struct node{
	int a1,a2,a3;
}a[100010];
bool cmp(node a,node b){
	return (max({a.a1,a.a2,a.a3})>max({b.a1,b.a2,b.a3}));
}
void solv(){
	vector<int> x,y,z;
	multiset<int> s;
	for(int i=1;i<=n;i++){
		if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3){
			x.push_back(i);
		}else if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3){
			y.push_back(i);
		}else{
			z.push_back(i);
		}
	}
	int ans=0;
	for(int i=0;i<x.size();i++){
		ans+=a[x[i]].a1;
	}
	for(int i=0;i<y.size();i++){
		ans+=a[y[i]].a2;
	}
	for(int i=0;i<z.size();i++){
		ans+=a[z[i]].a3;
	}
	if(x.size()>n/2){
		for(int i=0;i<x.size();i++){
			s.insert(a[x[i]].a1-max(a[x[i]].a2,a[x[i]].a3));
		}
		int cnt=0;
		for(multiset<int>::iterator it=s.begin();cnt<x.size()-n/2;cnt++,it++){
			ans-=*it;
		}
	}
	if(y.size()>n/2){
		for(int i=0;i<y.size();i++){
			s.insert(a[y[i]].a2-max(a[y[i]].a1,a[y[i]].a3));
		}
		int cnt=0;
		for(multiset<int>::iterator it=s.begin();cnt<y.size()-n/2;cnt++,it++){
			ans-=*it;
		}
	}
	if(z.size()>n/2){
		for(int i=0;i<z.size();i++){
			s.insert(a[z[i]].a3-max(a[z[i]].a2,a[z[i]].a1));
		}
		int cnt=0;
		for(multiset<int>::iterator it=s.begin();cnt<z.size()-n/2;cnt++,it++){
			ans-=*it;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a+1,a+n+1,cmp);
		solv();
	}
	return 0;
}
