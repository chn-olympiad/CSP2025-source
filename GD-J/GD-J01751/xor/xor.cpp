#include <iostream>
#include <cstdio>
using namespace std;
int a[100005],n,k;long long cnt=0;bool visit[10005],ab=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if (a[i]>1) ab=0;
	}
	if (ab){
		if (k==1){
			for (int i=1;i<=n;i++) if (a[i]==1) cnt++;
		}else{
			for (int i=1;i<=n;i++){
				if (a[i]==0) cnt++;
				if (a[i]==1&&a[i+1]==1){
					cnt++;
					i++;
				}
			}
		}
		cout<<cnt;
		return 0;
	}
    for (int i=1;i<=n;i++){
    	for (int j=1;j<=n-i+1;j++){
    		int ans=a[j];
    		if (!visit[j]){
	    		for (int l=j+1;l<=j+i-1;l++){
	    			if (visit[l]) break;
	    			ans^=a[l];
				}
	    		if (ans==k) cnt++;
	    		for (int l=j;l<=j+i-1;l++) visit[l]=1;
    		}
		}
	}
	cout<<cnt;
	return 0;
} 
