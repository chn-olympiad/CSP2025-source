#include "bits/stdc++.h"
#define long long
using namespace std;
const int N=1e6+10;
int a[N],flag[N];
int sum;
signed main(){ 
    freopen("xor.in","r","stdin");
    freopen("xor.out","w","stdout");
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		}
    int cnt=0;
   
	for(int i=1;i<=n;i++){
		int l=i;
		for(int j=i;j<=n;j++){
			int r=j;
			sum=sum^a[j];
			if(sum==k){
				for(int p=l;p<=r;p++){
					flag[p]++;
					if(flag[p]>1){
						cnt--;
						flag[p]--;
						break;
						}
					}
					cnt++;
				}
	    }
	    sum=0;
	}
	    cout<<cnt;
   return 0;
}

