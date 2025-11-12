#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[3][100000];
int sumold=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int ijk=a[i];
			for(int k=i+1;k<=j;k++){
				ijk=ijk^a[k];
			}
			if(ijk==k){
				b[1][s]=i;
				b[2][s]=j;
				s++;
//				cout<<i<<" "<<j<<endl;
			}
		}
	}
	int sum;
	for(int i=1;i<s;i++){
		int nm=i;
		int j=i+1;
		sum=1;
		while(j<=s){
			if(b[2][i]<b[1][j]){
				sum++;
				i=j;
				j++; 
			}else{
				j++;
			}
		}
		i=nm;
		if(sum>sumold){
			sumold=sum;
		}
	}
	cout<<sumold;
	return 0;
}

