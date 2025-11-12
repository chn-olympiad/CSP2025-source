#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long k,a[N];
int maxn=0,n;
void find(int l,int r,int cnt){
	if(r>n-1 && l>=n-1){
		if(cnt>maxn){
			maxn=cnt;
		}
		return;
	}else if(r>n-1 && l<n-1){
		l++;
		r=l;
		find(l,r,cnt);
	}
	long long t=a[l];
	for(long long i=l+1;i<=r;i++){
		t^=a[i];
	}
	if(t==k){
		cnt++;
		l=r+1;
		r=l;
		find(l,r,cnt);
	}else{
		r++;
		find(l,r,cnt);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	find(0,0,0);
	cout<<maxn<<endl;
	return 0;
} 
