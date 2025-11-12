#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+7;
int n,m;
string a,b; 
struct q{
	string x,y;
}A[N];
bool cmp(q x,q y){
	return x.x<y.y;
}
int lb(char c){
	int l=1,r=n;
	int ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(A[mid].x[0]>=c) r=mid-1,ans=mid;
		else l=mid+1; 
	}
	return ans;
}
int ub(char c){
	int l=1,r=n;
	int ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(A[mid].x[0]>c) r=mid-1,ans=mid;
		else l=mid+1; 
	}
	return ans;
}
bool ck(int y){ //判断第A[y].x带入能否使a变成b
	string x=A[y].x;
	string jk="";
	int l=a.find(x);
	if(a.find(x)==-1) return 0;
	int tot=0;
	for(int i=0;i<=b.size();i++){
		if(i>=l&&i<=l+A[y].x.size()-1) jk+=A[y].y[tot++];
		else jk+=a[i];
	}
	for(int i=0;i<jk.size();i++) if(jk[i]!=b[i]) return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>A[i].x>>A[i].y;
	sort(A+1,A+1+n,cmp);
	while(m--){
		int ans=0;
		cin>>a>>b;
		for(int j=1;j<=n;j++){
			if(ck(j)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
