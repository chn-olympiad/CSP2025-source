#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int n,k;
int arr[N];
struct qu{
	int l,r;
}arrl[N];
bool tmp(qu a,qu b){
	return a.l<b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int mid=1,sum;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum=arr[j];
			if(j+mid-1<=n){
				for(int h=j+1;h<=j+mid-1;h++){
					sum^=arr[h];
				}
				if(sum==k){
					arrl[++cnt].l=j;
					arrl[cnt].r=j+mid-1;
				}
			}
			
		}
		mid++;
	}
	sort(arrl+1,arrl+1+cnt,tmp);
	int rmin=arrl[1].r;
	int cntl=1;
	for(int i=1;i<=n;i++){
		if(arrl[i].l>rmin){
			rmin=arrl[i].r;
			cntl++;
		}
	}
	cout<<cntl;
	return 0;
}