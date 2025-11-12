#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int s[1010];
int o[1010];
bool cmp(int a,int b){
	return s[a]>s[b];
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		o[i]=i;
		cin>>s[i];
	}
	sort(o+1,o+n*m+1,cmp);
	int ans=0;
	for(int i=1;i<=n*m;i++){
		if(o[i]==1){
			ans=i;
			break;
		}
	}
	int b=ans/n;
	int c=0;
	if(b%2)  c=n-(ans-b*n)+1;
	else  c=ans-b*n;
	cout<<b+1<<" "<<c<<endl;
} 
