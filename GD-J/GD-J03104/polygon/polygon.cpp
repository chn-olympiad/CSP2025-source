#include<bits/stdc++.h>
using namespace std;
int q[5010];
long long s[5010];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>q[i];
		s[i] = s[i-1]+q[i];
		if(q[i] == 1)sum++;
	}
	if(sum==n)cout<<(n-1)*(n-2)/2;
	else if(n<=3){
		sort(q,q+n);
		if(q[0]+q[1]>q[2])cout<<1;
		else cout<<0;
	}
	return 0;
}
