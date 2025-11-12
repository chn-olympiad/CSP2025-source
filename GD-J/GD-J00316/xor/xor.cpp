#include<bits/stdc++.h>
using namespace std;
long long ans,x,p,n,m,j,i,k,l,b[500001][21],z,t,r,y,a[1000000],v[1000001];
string s;
bool pp(int a,int b){
	return a>b;
}
map<int,map<int ,int> >mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	if(m==0){
		for (i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0)ans++;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for (i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1)ans++;
		}
		cout<<ans;
		return 0;
	}
	for (i=1;i<=n;i++)cin>>a[i],a[i]^=a[i-1];
	for (i=1;i<=n;i++){
		for (j=i;j<=n;j++){
			k=a[j]^a[i-1];
			if(k==m){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
} 
