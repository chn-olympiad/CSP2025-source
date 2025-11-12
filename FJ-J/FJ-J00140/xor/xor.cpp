#include <bits/stdc++.h>  
using namespace std;
long long ans=0;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >>n >>k;
	vector<int> a(n);
	vector<pair<int,int>> p;
	for(int i=0;i<n;i++) cin >>a[i];
	int q=0,cnt=0;
	for(int i=0;i<n;i++){
	    q^=a[i];
	    if(q==k && cnt%2==0) ans++, cnt++;
	    else if (q==0 && cnt%2==1) ans++, cnt++;
	}
	cout <<ans;
	return 0;
}

