#include<bits/stdc++.h>
using namespace std;
long long p[1000000][2],pt,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long bi;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			bi=a[i];
			for(int b=i+1;b<j;b++){
				bi^=a[b];
			}
			if(bi==k){
				p[pt][0]=i;
				p[pt][1]=j;
				pt++;
			}
		}
	}
	long long cnt=0;
	for(int i=0;i<pt;i++){
		cnt++;
	}
	cout<<cnt;
}
