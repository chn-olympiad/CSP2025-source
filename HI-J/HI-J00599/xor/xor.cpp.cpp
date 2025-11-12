#include<bits/stdc++.h>
using namespace std;
int q[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,k;
	cin>>m>>k;
	bool t=0;
	for(int i=1;i<=m;i++){
		cin>>q[i];
		if(q[i]!=1) t=1;
	}
	if(t==0){
		int ans=0;
		for(int i=1;i<m;i++){
			ans+=i;
		}
		cout<<m;
		return 0;
	}

	
	return 0;
} 
