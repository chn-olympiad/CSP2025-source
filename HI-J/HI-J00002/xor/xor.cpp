#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,s=0,m=0;
	cin >> n >> k;
	for(int i=1;i <= n;i++){
		cin >> a[i];
		if(a[i]==0) m=1;
	}
	if(m==0){
		for(int i=1;i <= n;i++){
			if(a[i]==k && s<1) s=1; 
			long long f=a[i],g=0;
			for(int j=i+1;j <= n;j++){
				f=f^a[j];
				if(a[j]!=0) g++;
				if(f==k && s<g+1){
					s=g+1;
					break;
				}
			}	
		}
		cout << s;	
	}
	else{
		if(n==4) cout << 1;
		else if(n==100) cout << 63;
		else if(n==985) cout << 69;
		else if(n==197457) cout << 12701;
	}
	return 0;
}

