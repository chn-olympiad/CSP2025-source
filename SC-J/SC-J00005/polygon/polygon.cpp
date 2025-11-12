#include<bits/stdc++.h>
using namespace std;
int n,m,k,q,sum,b[5001];
const long long int MA=998244353;
void p(int zong,int xing,int dangx,int wei){
	if(dangx!=xing){
		wei+=1;dangx++;zong+=b[wei];
		p(zong,xing,dangx,wei);
	}else{
		if(zong>b[wei]*2){
			sum++;
			return ;
		}
	}
	return ;
}
void so(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k-i;j++){
			if(b[j]>=b[j+1]){
				int p=b[j];
				b[j]=b[j+1];
				b[j+1]=p;
			}
		}
	}
	for(int i=3;i<=k;i++){
		for(int j=1;j<=k;j++){
			for(int z=j;z<=k-i+1;z++){
				if(k-j+1>=i){
					p(j,i,1,z);
				}
				else break;
			}
		}
	}
	cout<<(sum+1)%MA;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;k=n;int w=0;
	for(int i=1;i<=k;i++){
		cin>>b[i];if(b[i]==1) w++;
	}
	if(w==k){
		cout<<((k-2)*(k-3)/2)%MA;
		return 0;
	}
	so();
	return 0;
}
