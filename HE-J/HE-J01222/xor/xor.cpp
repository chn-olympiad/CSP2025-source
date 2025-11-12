#include <bits/stdc++.h>
using namespace std;
const int NN=5e5+5;
long long Ans1,Ans2;
long long N,K,A[NN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>N>>K;
	for(int i=1;i<=N;i++){
		cin>>A[i];
		if(A[i]==K)Ans2++;
	}
	for(int i=1;i<=N;i++){
		if(A[i]==K){
			Ans1++;
		}else{
			for(int j=i+1;j<=N;j++){
				if(A[j-1]^A[j]==K){
					i=j;
					Ans1++;
					break;
				}else{
					A[j]=A[j-1]^A[j];
				}
			}
		}
	}
	if(Ans1>Ans2)cout<<Ans1<<endl;
	else cout<<Ans2;
	return 0;
}
