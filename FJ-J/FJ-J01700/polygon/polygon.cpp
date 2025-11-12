#include<bits/stdc++.h>
#include<algorithm>
long long tr[10000][2],l[5001],w=0,n;
using namespace std;
int bench(int a,int s,int h){
	int h2=0;
	s+=l[tr[a][0]];
	h2=l[tr[a][0]]>h?l[tr[a][0]]:h;
	if(s>h2*2){
		w++;
	}
	if(tr[a][1]!=0){
		for(int i=0;i<tr[a][1];i++){
			bench(a*n+i,s,h2);
		}
	}
	if(tr[a][1]==0){
		return 0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long span,i;
	cin>>n;
	tr[1][0]=1;
	for(i=1;i<10000;i++){
		if(tr[i][0]!=0){
			tr[i][1]=n-tr[i][0];
			for(int j=0;j<tr[i][1];j++){
				tr[n*i+j][0]=tr[i][0]+j+1;
			}
		}
	}
	for(i=1;i<=n;i++){
		cin>>l[i];
	}
	bench(1,0,0);
	for(i=0;i<n;i++){
		bench(n+i,0,0);
	}
	cout<<w%998244353;
	return 0;
}
