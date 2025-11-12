#include<bits/stdc++.h>
using namespace std;
const int N=10e5*2; 
//0->全是0 , 1->全是0或1 , 2->不能特判 
int special_judge(int a[],int n,int k){
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			if(a[i]!=1)return 2;
			else return 1; 
		}
	}
	return 0;
}
int Xor(int a[],int l,int r){
	int sum=a[l];
	for(int i=l+1;i<=r;i++){
		sum=(sum^a[i]);
	}
	return sum;
}
int n,k,num[N],ml;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	if(special_judge(num,n,k)==0){
		cout<<n-1;
		return 0;
	}
	else if(special_judge(num,n,k)==1){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(num[i]==1){
					cout<<max(i,n-i);
					return 0;
				}
			}
		}
		else if(k==0){
			int l,r;
			for(int i=1;i<=n;i++){
				if(num[i]==1){
					l=i;
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(num[n-i+1]==1){
					r=i;
					break;
				}
			}
			cout<<max(l,r);
			return 0;
		}
	}
	else {
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k;o<=n;o++){
						if(Xor(num,i,j)==k&&Xor(num,k,o)==k){
							ml=max(j-i+1,o-k+1);
						}
					}
				}
			}
		}
		cout<<ml;
	}
	return 0;
} 
