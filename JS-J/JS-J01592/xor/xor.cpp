// need long long ? need
// time ? O(n)
// space ? n
// max num ? n=5e5 k=2^20
// freopen ? yes
// part score code
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> v;
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	long long cnt=0;
	long long l=0;
	long long xors;
	while(l<n){
		if(l==n) break;
		xors=v[l];
		//cout<<l+1<<' ';
		while(xors!=k&&l<n){
			l++;
			xors^=v[l];
		}
		//cout<<xors<<' '<<l+1<<endl;
		l++;
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
