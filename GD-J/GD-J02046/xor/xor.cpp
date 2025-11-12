#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans=0;

bool is(int x,int y){
	//if(x==y)return a[x];
	int cnt=0;
	for(int i=x;i<=y;i++){
		cnt=cnt^a[i];
	}
	return (cnt==k);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)cin >> a[i];
	int lll=0;
	for(int l=1,r=1;r<=n &&l<=n;){
		//cout << is(2,4);
		if(is(l,r)){
			//cout << l<<" "<<r<<endl;
			l=r+1;
			lll=l;
			r=l;
			ans++;
		}
		else{
			if(r==l){
				l=lll;
				r++;
			}
			else{
				l++;
			}
		}
	}
	cout << ans;
	return 0;
}
