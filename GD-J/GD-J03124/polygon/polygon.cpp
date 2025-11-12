#include<bits/stdc++.h>
#define LL long long
#define itn long long
using namespace std;
#define N 5005 
LL n;
LL a[N];
bool vis[N]; 
int maxn(int i,int j,int k){
	int t=max(i,max(j,k));
	return t*2;
}
LL A(int u){
	LL k=1;
	for(int i=2;i<=u;i++) k*=i;
	return k;
}
LL answer(itn u){
	int temp=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(i>=k||i>=j||j>=k) continue;
				temp++;
			}
		}
	}
	return temp;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool k=1;
	for(itn i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) k=0;
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>maxn(a[1],a[2],a[3])) cout<<1;
		else cout<<0;
	}else if(k){
		cout<<answer(n);
	}
	return 0;
}
