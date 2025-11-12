#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int a[MAXN],n,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		int num_i=a[i],maxn=a[i];
		for(int j=i+1;j<n;j++){
			num_i+=a[i];
			maxn=max(maxn,a[i]);
			if(num_i>=maxn*2){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
