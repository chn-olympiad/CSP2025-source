#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500005];
//struct edge{
//	int l,r;
//};
deque<int>q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i]^a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[j]^a[i-1])==k){
//				cout<<i<<' '<<j<<' '<<(a[j]^a[i-1])<<"\n";
				while(!q.empty()&&q.back()>=j)q.pop_back();
				if(q.empty()||q.back()<i)q.push_back(j);
				break;
			}
		}
	}
//	while(!q.empty()){
//		cout<<q.front().l<<' '<<q.front().r<<'\n';
//		q.pop_front();
//	}
	cout<<q.size();
	return 0;
}

