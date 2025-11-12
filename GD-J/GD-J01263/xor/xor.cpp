#include<bits/stdc++.h>
using namespace std;
int n,k,a[10000000],molinans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<n;i++){
		int summolin=0;
		for(int j=i;j<=n;j++){
			if(j==i)summolin=a[j];
			else summolin=summolin xor a[j];
			//cout<<i<<' '<<j<<'\n';
			//cout<<summolin<<'\n';
			if(summolin==k){
				molinans++;
				i=j;
				break;
			}
		}
	}
	cout<<molinans;
	return 0;
	//记得检查freopen和调试有没有删掉
}   //要存到D盘


