#include<bits/stdc++.h>

using namespace std;

#define LL long long

const int N=2e6+7;

LL n,m,cnt,ans,a,b;
LL A[N],B[N];
bool bl[N];

bool cmp(LL x,LL y){
	return x>y;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}
	B[0]=0;a=1;cnt=0;bl[0]=1;
	for(int i=1;i<=n;i++){
		B[i]=B[i-1]^A[i];
		ans=B[i]^m;
		if(bl[ans]){
			cnt++;
			for(int j=a;j<=i;j++){
				bl[B[j]]=0;
			} 
			a=i+1;
			B[i]=0;bl[0]=1;
		}
		else{
			bl[B[i]]=1;
		}
	}
	cout<<cnt<<endl;
	
	return 0;
}
