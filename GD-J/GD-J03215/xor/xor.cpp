#include<bits/stdc++.h>

using namespace std;
const int LRMax=1e5+10;
int LR[LRMax]; 
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int N,K;
	int Q=0;
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++){
		cin>>LR[i];
		if(K==LR[i]){
			Q++;
		}
	}for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j++){
			int sum=0;
			for(int y=i;y<j;y++){
				sum+=y;
			}if(sum==K){
				Q++;
			}
		}
	}
	cout<<Q-1<<endl;
	return 0;
}
