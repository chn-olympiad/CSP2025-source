#include<bits/stdc++.h>
using namespace std;
int b[50005],n,k;
long long sum=0;
long long h(int o,int p,int s,long long w){
	if(o==0)return s+p*w;
	if(p==0)return s+o*w;
	if(o%2==p%2)return h(o/2,p/2,s,w*2);
	else return h(o/2,p/2,s+w,w*2);
}
void ma(int l,int r,int c[50005]){
	for(int i=l;i<r;i++){
		if(c[i]==k){
			sum++;
			ma(l,i-1,c);
			ma(i+1,r,c);
			return;
		}else{
			c[i]=h(c[i],c[i+1],0,1);
			if(c[i]==k){
				sum++;
				ma(l,i-1,b);
				ma(i+1,r,b);
				return;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin >> b[i];
	}
	ma(0,n-1,b);
	cout << sum << endl;
	return 0;
}
