#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int c[N];
vector<long long> vec;
#define int long long
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	queue<int> q;
	for(int j=0;j<n;j++){
		q.push(a[j]);
	}
	for(int i=3;i<=n;i++){
		int b[n/i];
		int sum=0;
		for(int j=0;j<n/i;j++){
			b[j]=q.front();
			sum+=q.front();
			q.pop();
		}
		int maxn=INT_MIN;
		for(int j=0;j<n/i;j++){
			if(b[j]>maxn){
				maxn=b[j];
			}
		}
		if(sum>maxn*2){
			vec.push_back(sum);
		}
		for(int j=0;j<n;j++){
			q.push(a[j]);
		}
	}
	cout << vec.size()%998244353;
	return 0;
}
