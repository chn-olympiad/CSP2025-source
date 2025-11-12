#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
int n,m,c[505],p[505],lk,ans,lq,q[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i=1;i<=n;i++){
		cin >> c[i];
	}
	for (int i=1;i<=n;i++) q[i]=p[i]=i;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			swap(p[i],p[j]);
			lk=lq=0;
			for (int k=1;k<=n;k++){
				if (lk>=c[p[i]]){
					lk++;
//					continue;
					for (int kk=k;kk<n;kk++){
						p[kk]=p[kk+1];
					}
				}
				if (s[i]=='1') lq++;
				else{
					lk++;
				} 
			}
			if (lq>=m){
				ans++;
				ans%=M;
			}
			for (int i=1;i<=n;i++){
		    	p[i]=q[i];
		    }
    	}
	}
	cout << ans;
	return 0;
}
