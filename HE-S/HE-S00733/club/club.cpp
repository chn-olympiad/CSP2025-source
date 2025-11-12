#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int const maxn=1e5+5;
int t,n,all[maxn][3],a[maxn/2];
int allmax(int n,int m,int k){
	int temp=max(n,max(m,k));
	if(temp==n){
		return 0;
	}if(temp==m){
	return 1;
	}if(temp==k){
		return 2;
	}
}
int main(){
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
	cin>>t;
	for(int l=0;l<t;l++){
		int cnt=0,k=0;
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>all[i][j];
			}
		}
		for(int i=0;i<3;i++){
			int temp =n/2;
			for(int j=0;j<n;j++){
				if(k==temp){
					sort(a,a+k,greater<int>());
					if(all[j][i]>a[k]){
						a[k]=all[j][i];
						cnt=cnt-a[k]+all[j][i];
					}
				}else{
					a[k]=all[j][i];
					cnt+=all[j][i];
					k++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
