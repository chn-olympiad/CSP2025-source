#include<iostream>
using namespace std;
int n,m,num[1000010],sum = 0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i =0;i<n;i++) cin>>num[i];
	for(int i =0;i<n;i++){
		int jj = 0;
		for(int j = i+1;j<n;j++){
			int kk = 0;
			jj ^= num[j];
			for(int k = i;k>=0;k--){
				kk ^= num[k];
				if(kk == jj && jj == m){
					sum+=2;
				}
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
