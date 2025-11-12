#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
char g[N];
cin.getline(g,N);
	int h[N];
	for(int i=0;i<=N;i++){
		h[i]=-1;
	}
	for(int i=0;i<=N;i++){
		if(g[i]==1||g[i]==2||g[i]==3||g[i]==4||g[i]==5||g[i]==6||g[i]==7||g[i]==8||g[i]==9||g[i]==0){
		h[i]=g[i];
		}
	}
	sort(h+N,h);
	for(int i=0;i<N;i++){
		if(h[i]!=-1){
			cout<<h[i];
		}
	}
	return 0;
}
