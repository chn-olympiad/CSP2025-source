#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k;
int A[N];
int x[N];
struct range{
	int l,r;
	friend bool operator<(range a,range b){
		return a.r<b.r;
	}
};
int ans;
vector<range> r;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		x[i]=(x[i-1] xor A[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((x[j]^x[i-1])==k)
				r.push_back({i,j});
		}
	}
	sort(r.begin(),r.end());
	for(int t=0,i=0,flag=0;i<r.size();ans++,i++){
		while(t>=r[i].l){
			i++;
			if(i>=r.size()){
				flag=1;
				break;
			}	
		}
		if(flag)
			break;
		t=r[i].r;
	}
	cout<<ans<<endl;
	return 0;
}
