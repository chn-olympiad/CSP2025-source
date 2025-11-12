#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,m,num[N],ans=0;
int calc(int num[],int x,int y,int k){
	int ans=0,d=0;
	for(int i=x;i<=y;++i){
		if(num[i]==k){
			++ans;
			calc(num,i+1,y,k);
		}
		else if(i==y){
			if(num[i]==k)++ans;
		}
		else{
			d=d^(num[i]^num[i+1]);
			if(d==k){
				++ans;
				calc(num,i+1,y,k);
			}
		}
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>num[i];
	cout<<calc(num,1,n,k);
	return 0;
}

