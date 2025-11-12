#include<bits/stdc++.h>
using namespace std;
//a^b^b=a
const int N=5e5+10;
int n,m,a[N],sum[N];
int query(int l,int r){
	return sum[r]^sum[l-1];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int st=1,i=1,j=1,cnt=0;
	for(i;i<=n;i++){
		//cout<<i<<" "<<st<<endl;
		for(j=st;j<=i;j++){
			if(query(j,i)==m){
				st=i+1;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}

