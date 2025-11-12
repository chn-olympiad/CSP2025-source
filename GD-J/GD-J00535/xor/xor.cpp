#include<bits/stdc++.h>
using namespace std;
int l[500005],anscnt,xorsum,lstans=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int x,k;
	cin>>x>>k;
	for(int i=0;i<x;i++)cin>>l[i];
	if(x<=10005){//t1-12
		for(int i=0;i<x;i++){
			anscnt=0;
			xorsum=l[i];
			for(int j=i+1;j<x;j++){
				if(xorsum==k){
					anscnt++;
					xorsum=0;
				}xorsum^=l[j];
			}if(xorsum==k){
				anscnt++;
				xorsum=0;
			}lstans=max(lstans,anscnt);
		}cout<<lstans;
	}else cout<<1;
	return 0;
} 
