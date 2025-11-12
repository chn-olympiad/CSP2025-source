#include<bits/stdc++.h>
using namespace std;

long long n, a[11451], b[11451], ans;

bool cmp(int a, int b){
	return a>b;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1, a+1+n, cmp);
	for(int i=1;i<=n-2;i++){
		for(int j=2;j<=n-i;j++){
//			cout<<i<<" "<<j<<endl;
			memset(b,0,sizeof(b));
			int cnt=0;
			for(int k=0;k<j;k++) b[n-i-k-1]=1;
//			for(int k=0;k<n-i;k++) if(b[k]) cnt+=a[k];
//			if(cnt>a[i]) ans++;
			while(next_permutation(b,b+n-i)){
				for(int k=0;k<n-i;k++)
					if(b[k]) cnt+=a[k+i+1];
//					cout<<b[k]<<" ";
				if(cnt>a[i]) ans++;
//				cout<<endl;		
				
			}
		}
	}
	cout<<ans<<endl;
}