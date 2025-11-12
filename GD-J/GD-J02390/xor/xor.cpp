#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100001],num=0;
bool flag[100001]={false};
bool qz(long long l,long long r){
	long long he=a[l];
	if(flag[l]) return false;
	for(int k=l+1;k<=r;k++){
		he=he^a[k];
		if(flag[k]) return false;
	} 
	return he==k;
}
void flaging(long long l,long long r){
	for(int k=l;k<=r;k++){
		flag[k]=1;
	} 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++) {
		cin>>a[i];
		flag[i]=false;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(qz(i,j)) {
				num++;
				flaging(i,j);
			}
		}
	}
	cout<<num;
	return 0;
}

