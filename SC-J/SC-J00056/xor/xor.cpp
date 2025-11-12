#include<bits/stdc++.h>
using namespace std;
const int N=500000+100;
int a[N][30]={0},sum[N][30]={0},ax=1;
int b[30];
int query(int l,int r){
	if(l>r)swap(l,r);
	for(int i=1;i<=ax;i++){
		b[i]=sum[r][i]-sum[l-1][i];
	}
	int t=0;
	for(int i=21;i>=1;i--){
		t=t*2+b[i]%2;
	}
	return t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		int j=0;
		for(int asd=1;asd<=ax;asd++){
			sum[i][asd]=sum[i-1][asd];
		}
		while(t>0){
			j++;
			a[i][j]=t%2;
			if(a[i][j])ax=max(ax,j);
			t=t>>1;
			sum[i][j]+=a[i][j];
		}
	}
	int j=1,ans=0;
	for(int i=1;i<=n;i++){
		for(int h=j;h<=i;h++){
			if(query(h,i)==k){
				j=i+1;
//				cout<<h<<" "<<i<<"\n";
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}