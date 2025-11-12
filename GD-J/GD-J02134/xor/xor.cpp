#include<bits/stdc++.h>
using namespace std;
int a[1145140]={};
int sb(int s,int b){
	int sum=0;
	for(int i=s;i<=b;i++){
		sum=sum^a[i];
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j and a[j]==k){
				cnt++;
			}else{
				if(sb(i,j)==k){
				cnt++;
			}
			}
			
		}
	}
	cout<<cnt;
	return 0;
} 

