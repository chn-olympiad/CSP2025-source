#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,k,a[N],s[N],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1] xor a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((s[r] xor s[l-1])==k){//the () cost me 15mins:(
				cnt++;
				l=r;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}//written by zsz0804_/GD-J00722
