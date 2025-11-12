#include<bits/stdc++.h>
using namespace std;
int n,ji,jjj;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int yy[10008];
	for(int i=1;i<=n;i++){
		cin>>yy[i];
	}
	sort(yy,yy+n);
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			ji+=yy[j];
			if(ji<yy[i]*2){
				jjj++;
				jjj%=998244353;
			}
		}
		ji=0;
	}
	cout<<jjj;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
