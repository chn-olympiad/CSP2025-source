#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n;
	string s;
	cin>>s;
	int t=0,nx=0;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1,k=1;;i++,k++){
		if(a[i]>nx&&s[i-1]=='1'){
			t++;
			nx=0;
		}else{
			nx++;
		}
		i%=m;
		k%=998244353;
		if(t==n){
			cout<<k;
			break;
		}
	}
	return 0;
}
