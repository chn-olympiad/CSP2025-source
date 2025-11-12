#include<bits/stdc++.h>
using namespace std;
int n,k,q[1010];
void solve(){
	int num=0,i;
	for(i=1;i<=n;i++){
		scanf("%d",&q[i]);
	}
	i=1;
	while(i<=n){
		if(q[i]==0) num++;
		else if(q[i]==q[i+1]){
			num++;
			i++;
		}
		i++;
	}
	cout<<num;
}
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    if(k==0){
    	solve();
	}
	return 0;
}
//20·Ö£ºµ±k=0 
