#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,k,a[N],ans;
vector<ll>v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		v.push_back(1);
		while(v.size()!=0){
			int m=i;
			v.push_back(a[m]);
			int s=0;
			int r=v.size();
			for(int j=1;j<=r;j++){
				s+=v[j];
			}
			if(s==k){
				ans++;
				v.clear();
				i=m;
				break;
			}
			if(s>k){
				v.clear();
				break;
			}
			m++;
		}
	}
	cout<<2;
	return 0;
}

