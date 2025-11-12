#include<bits/stdc++.h>
using namespace std;
long long n,s[5005],qz[5005],x,ans,tmp;
long long jl[5005][5005],bg[500005];
void zh(int x,int y){
	tmp=1;
	for(int i=1;i<=y-x;++i){
		tmp*=i;
		tmp%=998244353;
	}
	for(int i=x;i<=y;++i){
		ans+=tmp/(i-x+1);
		ans%=998244353;
		for(int j=x;j<i;++j){
			jl[j][i]=1;
		}
	} 
}
void kick(int o,int x){
	for(int l=o;l>=1;--l){
		for(int i=1;i+l-1<o;++i){
			int j=i+l-1;
			if(qz[j]-qz[i-1]<x&&!jl[i][j]){
				zh(i,j);
				//cout << ans << ' ' << i << ' ' << j << endl;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> s[i];
		qz[i]=qz[i-1]+s[i];
	}
	sort(s+1,s+n+1);
	for(int i=3;i<=n;++i){
		if(qz[i-1]==s[i]){
			++ans;
		}else if(qz[i-1]>s[i]){
			x=qz[i-1]-s[i];
			kick(i,x);
			ans%=998244353;
		}
	}
	cout << ans;
	return 0;
}
