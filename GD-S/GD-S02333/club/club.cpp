#include<bits/stdc++.h>
using namespace std;
const int it=1000000;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t,answer[it];
	cin>>t;
	int k=0;
	while(t--){
		k++;
		int n,a[it][3];
		int a1=0,a2=0,a3=0,sum=0;
		cin>>n;
		int r=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			int mmax=0;
			for(int j=1;j<=3;j++){
				if(mmax<a[i][j]){
					if(j==1){
						a1++;
						if(a1>r){
							continue;
						}
						else{
							mmax=a[i][j];
						}
					}
					else if(j==2){
							a2++;
						if(a2>r){
							continue;
						}
						else{
							mmax=a[i][j];
						}
					}
					else{
						a3++;
						if(a3>r){
							break;
						}
						else{
							mmax=a[i][j];
						}
					}
				}
			}
			sum+=mmax;
		}
		answer[k]=sum;
	}
	for(int i=1;i<=t;i++){
		cout<<answer[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
