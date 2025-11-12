#include<bits/stdc++.h>
using namespace std;
int n,m,li[500001],re[500001],cnt,p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>li[i];
		re[i]=!re[i-1]|li[i];
	}
	for(int i=1;i<=n;i++){
		if(!re[i]|li[p]==m){
			cnt++;
			p=i;
			continue;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<re[i]<<" ";
	}
	cout<<"\n"<<cnt+4;
	return 0;
}
