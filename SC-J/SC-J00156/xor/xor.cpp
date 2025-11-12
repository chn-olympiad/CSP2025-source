#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int a[N];
vector<int> p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			cnt++;
			p.clear();
			continue;
		}
		bool f=false;
		for(int j=0;j<(int)p.size();j++){
			p[j] = p[j] xor a[i];
			if(p[j]==k){
				cnt++;
				p.clear();
				f=true;
				break;
			}
		}
		if(f==false) p.push_back(a[i]);
	}
	cout<<cnt<<"\n";
	return 0;
}