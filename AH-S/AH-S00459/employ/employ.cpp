#include<bits/stdc++.h>
using namespace std;
long long as=0;
int n,m,a[505];
string s;
void dp(bool bb[],int k,int w,int q){
	if(w<m) return ;
	if(k==n){
		as++;
		as=as%998244353;
		return ;
	}
	for(int i=0;i<n;i++){
		if(bb[i]==1){
			continue;
		}
		bb[i]=1;
        if(s[k]=='0' || a[i]<=q){
			dp(bb,k+1,w-1,q+1);
		}
		else{
		    dp(bb,k+1,w,q);
		}
		bb[i]=0;
	}
	return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool bb[n]={0};
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dp(bb,0,n,0);
	cout<<as;
	return 0;
}
