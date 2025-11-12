#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;int a[N];
int x[N];int num;
set<int> se;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	x[1]=a[1];
	for(int i=2;i<=n;i++)
		x[i]=x[i-1]^a[i];
	se.insert(0);
	for(int i=1;i<=n;i++){
		int xx=x[i]^k;
		if(se.count(xx)){
			num++;
			se.clear();
		}
		se.insert(x[i]);
	}
	cout<<num;
	return 0;
}