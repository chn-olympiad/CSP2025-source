#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
ll n=1,k=3,ans;
vector<int> a,b;
int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;++i){
	    int s;
		cin>>s;
		a.push_back(s);
	    if(i>0)s^=b[i-1];
	    b.push_back(s);
	}
	
	for(int i=0;i<n;++i){
		if(a[i]==k){ans++;continue;}
		for(int j=i+1;j<n;++j){
		    int z=b[j];
		    if(i>0)z^=b[i-1];
			if(z==k){
				i=j;
				ans++;break;
			}
		}
	}
	cout<<ans;
	return 0;
}


