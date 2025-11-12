#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],idx,x,cnt;
void js(int id,int l){
	int g=a[id];
	for(int i=id+1;i<=id+l-1&& a[i]!=-1;i++){
		g^=a[i];
	}
	if(g==k){
		cnt++;
	for(int i=id;i<=id+l-1;i++){
		a[i]=-1;
	}	
	} 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	for(int i=1;i<=n;i++){
		cin >>x;	
		if(x==k){
			cnt++;
			a[idx]=-1;
		}
		else a[idx]=x;
		idx++;
	}
	for(int i=2;i<=idx;i++){//个数 
		for(int j=1;j<=idx-i+1&& a[j]!=-1;j++){//第一个数下标 
			js(j,i);
		}
	}
	cout <<cnt;
	return 0;
} 