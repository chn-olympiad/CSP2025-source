#include<bits/stdc++.h>
using namespace std;
long long ans[105][105],c1=1;
struct node{
	long long x,y;
}q[105];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n);
    
    for(long long i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			for(long long k=i;k<=j;k++){
				ans[i][j]^=a[k];
			}
		}
	}
	long long cnt=0;
    for(long long i=1;i<=n;i++){
    	for(long long j=i;j<=n;j++){
    		if(ans[i][j]==k){
    			cnt++;
    			q[c1].x=i;
    			q[c1].y=j;
    			c1++;
			}
		}
	}
	for(long long i=2;i<c1;i++){
		for(long long j=1;j<=i;j++){
			if(q[i].x<=q[j].y&&i!=j){
				q[i].y=0;
				cnt--;
			}
		}
	}
    cout<<cnt;
	return 0;
}