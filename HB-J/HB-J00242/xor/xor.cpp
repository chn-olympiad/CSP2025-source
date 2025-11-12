#include <bits/stdc++.h>
using namespace std;
long long n,k;
int a[1000006];
bool yihuohe(int l, int r, int k){
	long long ansu = 0;
	for(int k =l; k<=r; k++){
		ansu = ansu | a[k];
	}
	if(ansu == k)
		return true;
	return false;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	if(n <= 2 && k == 0){
		int kk =0;
		int num = 1;
		for( int i=1; i<=n; i++){
			if(num == 2) kk++;
			num++;
		}
		cout<<kk<<endl;
		return 0;
	}
	/*if(n <= 10 && k<=1){
		
	}
	if(n<=100 && k ==0){
		int kk =0;
		int num = 1;
		
		cout<<kk<<endl;
		return 0;
	}
*/
	
	long long ans = 0;
	int ql[1000005];
	int qr[1000005];
	int k = 1;
	//baoli
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if(yihuohe(i, j, k)){
				ql[k] = i;
				qr[k] = j;
				k++;
			}
				
		}
	}
	cout<<k<<endl;
	for(int i = 1; i<=k; i++){
		cout<<"["<<ql[i]<<","<<qr[i]<<"]"<<" ";
	}
	cout<<endl;
	//chachong
	for(int i = 1; i<k; i++){
		if(qr[i] > ql[i+1]){
			continue;
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
