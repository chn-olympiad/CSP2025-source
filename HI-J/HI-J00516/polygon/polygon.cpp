#include<bits/stdc++.h>
using namespace std;
int tree[5000+5];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tree[i];
	}
	int out_cnt=0;
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			int cnt=0;
			int max_n=-1;
			for(int b=j;b<=b+i;b++){
				cnt+=tree[b];
				max_n=max(max_n,tree[b]);
			}
			if(cnt>max_n*2){
				out_cnt++;
			}
		}
		
	}
	cout<<out_cnt;
	return 0;
} 
