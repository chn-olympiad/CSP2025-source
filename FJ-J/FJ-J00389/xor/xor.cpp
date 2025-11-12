#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int n,k;
int qe[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>qe[1];
	for(int i=2;i<=n;i++){
		int num;
		cin>>num;
		qe[i]=num^qe[i-1];
	}
	int cnt=0,ma=0;
	if(qe[1]==k){
		cnt++;
		ma=1;
	}
	for(int i=1;i<=n;i++){
		if(qe[i]==k) cnt++;
	}
	cout<<cnt;
	/*for(int i=2;i<=n;i++){
		for(int j=i;j>0;j--){
			if(qe[i]^qe[j-1]==k && j>ma){
				cout<<j<<" "<<i<<endl;
				cnt++;
				ma=i;
			}
		}
	}
	cout<<cnt<<endl;*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}