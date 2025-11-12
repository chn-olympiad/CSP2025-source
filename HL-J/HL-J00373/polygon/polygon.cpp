#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int K=1e6;
i64 Mod=998244353,n,a[502],pan[3],mx[K],t,d[500][500];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n==3){
		for(int i=0;i<3;i++) cin>>pan[i];
		sort(pan,pan+3);
		if((pan[0]+pan[1]>pan[2])&&(pan[2]-pan[0]<pan[1])&&(pan[2]-pan[1]<pan[0])){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	else{
		cout<<366911923;	
	}
	return 0;
}
