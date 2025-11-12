#include<bits/stdc++.h>
using namespace std;
int n,m;
int i1;
vector<int>ni;
vector<int> mi;
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	ni.resize(n);
	mi.resize(n);
	for(int i=0;i<n;i++){
		cin>>ni[i];
		if(ni[i]==1){
			i1++;
		}
	}
	if(i1<m){
		cout<<0<<endl;
	}
	for(int i=0;i<n;i++){
		cin>>mi[i];
	}
	cout<<(n-m)*m;
	return 0;
}
