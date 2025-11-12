#include<bits/stdc++.h>
using namespace std;

int len[5005],lenh[5005];  //lenhÇ°×ººÍ 
bool pd(int front,int l){
	if(lenh[front+l-1]-lenh[front-1]>len[front+l-1]*2){
		return 1;
	} 
	return 0;
}
long long cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len[i];
	}
	sort(len+1,len+n+1);
	for(int i=1;i<=n;i++){
		lenh[i]=lenh[i-1]+len[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(pd(j,i)){
				++cnt;
				cnt%=998244353;
			}
		}
	}
	cout<<cnt;
	return 0;
}


