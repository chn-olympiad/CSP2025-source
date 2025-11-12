#include<bits/stdc++.h>
using namespace std;
const int INF=5*1e5+1;
int n,k,a1[INF],cnt2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i){
		scanf("%d",&a1[i]);
    }if(k){
    	for(int i=0;i<n;i++){
    		if(a1[i]!=a1[i+1] && i+1<n) cnt2++;
    		if(a1[i]==1) cnt2++;
		}
	}else{
		for(int i=0;i<n;i++){
    		if(a1[i]==1 && a1[i+1]==1 && i+1<n) cnt2++;
    		if(a1[i]==0) cnt2++;
		}
	}printf("%d",cnt2);
	return 0;
}
