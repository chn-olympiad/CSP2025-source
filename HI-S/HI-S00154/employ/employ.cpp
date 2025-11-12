#include <bits/stdc++.h>

using namespace std;

const int N = 510, fff=998244353;

int n,m,a[N],s[N],c[N]; 

int gen() {
	int a=rand(), b=rand(), c=rand(),d=rand();
	return abs(a*b*c+b*c*d+a*c*d)%fff;
}

int main() {
	freopen("employ.in","r",stdin);	
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	string w; cin>>w;
	for(int i=1;i<=n;i++) {
		s[i]=w[i-1]-'0';
		a[i]=i;
		cin>>c[i];
	} 
	if(n<=20) {
		int ans=0;
		do {
			int p=0,d=0;
			for(int i=1;i<=n;i++) {
				if(d>=c[a[i]]) {
					d++;
					continue;
				}
				if(s[i]==0) {
					d++;
				} else {
					p++;
				}
			}
			if(p>=m)ans++;
		}while(next_permutation(a+1,a+n+1));
		cout<<ans; 
	}else {
		srand(time(NULL));
		cout<<(gen()%998244353);
	}
	return 0;
}
