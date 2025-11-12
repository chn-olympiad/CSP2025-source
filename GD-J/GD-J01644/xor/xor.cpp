#include<bits/stdc++.h>
using namespace std;

int a[500005],cnt,lr[500002][2];

int result(int l,int r){
	int res;
	for(int i=l;i<r;i++){
		res=a[i]^a[i+1];
	}
	return res;
}

bool same(int l1,int l2,int r1,int r2){
	return l2<r1&&l1<r2;
}

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int l=0;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(result(l,r)==k){
				cnt++;
				lr[cnt][0]=l;
				lr[cnt][1]=r;
			} 
		}
	}
	for(int i=0;i<=cnt;i++){
		if(lr[i][0]>0){
			for(int j=i+1;j<=cnt;j++){
				if(same(lr[i][0],lr[j][0],lr[i][1],lr[j][1])&&lr[j][0]>0){
					cnt--;
					lr[j][0]=-1;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
