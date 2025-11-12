#include<bits/stdc++.h>
using namespace std;
long long n,k;int v[500020];
unsigned int xor_z(unsigned int x,unsigned int y){
	unsigned int ans=0,w=0;
	while(x||y){
		bool a=x&1,b=y&1;
		if(a!=b){
			ans+=pow(2,w);
		}
		x=x>>1;y=y>>1;
		w++;
	}
	return ans;
}

int xor_h(int l,int r){
	if(l==r)return v[l];
	int ans=v[l];
	for(int i=l+1;i<=r;++i){
		ans=xor_z(ans,v[i]);
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;

	for(int i=1;i<=n;++i){
		cin>>v[i];
	}

	int ansk=0;
	bool p=1;
	for(int i=1;i<=n;p=1){
		for(int j=i;j<=n;++j){
			if(xor_h(i,j)==k){
				ansk++;
				i=j+1;p=0;
				break;
			}
		}
		if(p)++i;
	}
	
	cout<<ansk<<endl;
	return 0;
}

/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0 
2 1 0 3
*/
