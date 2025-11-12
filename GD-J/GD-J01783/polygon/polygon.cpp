#include<bits/stdc++.h>
using namespace std;
#define int long long
deque<int>s;
int chop[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>chop[i];
	}
	
	int h=1;
	for(int i=1;i<=n;i++){
		h=h*i%998244353;
	}
	cout<<h;
	return 0;
}
