#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,mx,re,num;
struct Node{
	int x,y,z;
}a[N],b[N];
vector<Node> ve[5];
bool sx1(Node x,Node y)
{
	if(max(x.y,x.z)-x.x==max(y.y,y.z)-y.x){
		return x.y-x.z>y.y-y.z;
	}
	return max(x.y,x.z)-x.x>max(y.y,y.z)-y.x;
}
bool SX1(Node x,Node y)
{
	if(x.y-x.z==y.y-y.z) return x.y>y.y;
	return x.y-x.z>y.y-y.z;
}
void solve()
{
	re=num=0;
	for(int i=1;i<=3;i++){
		ve[i].clear();
	}
	for(int i=1;i<=n;i++){
		int tmp=max(a[i].x,max(a[i].y,a[i].z));
		if(tmp==a[i].x){
			re+=a[i].x;
			ve[1].push_back(a[i]);
		}
		else if(tmp==a[i].y){
			re+=a[i].y;
			ve[2].push_back(a[i]);
		}
		else{
			re+=a[i].z;
			ve[3].push_back(a[i]);
		}
	}
	if(ve[2].size()>n/2){
		for(int i=1;i<=n;i++){
			swap(a[i].x,a[i].y);
		}
		solve();
	}
	else if(ve[3].size()>n/2){
		for(int i=1;i<=n;i++){
			swap(a[i].x,a[i].z);
		}
		solve();
	}
	else if(ve[1].size()>n/2){
		sort(ve[1].begin(),ve[1].end(),sx1);
		int s2=ve[2].size(),s3=ve[3].size();
		for(int i=0;i<ve[1].size()-n/2;i++){
			b[++num]=ve[1][i];
		}
		sort(b+1,b+num+1,SX1);
		for(int i=1;i<=num;i++){
			if(s2<n/2&&(b[i].y>b[i].z||s3==n/2)){
				re+=b[i].y-b[i].x;
				s2++;
			}
			else{
				re+=b[i].z-b[i].x;
				s3++;
			}
		}
		cout<<re<<'\n';
	}
	else{
		cout<<re<<'\n';
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		solve();
	}
	return 0;
}
