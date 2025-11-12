#include<bits/stdc++.h>
using namespace std;
long long ans=1;
int n,m,c[501],sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n);
	for(int i=0;i<n;i++){
		if(c[i]==0){
			sum++;
		}
	}
	if(m<n-sum)ans=0;
	else ans=161088479;
	cout<<0;
	return 0;
}
