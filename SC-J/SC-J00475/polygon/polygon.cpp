#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,a[N],num;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				if(a[i]+a[j]+a[l]>max(max(a[i],a[j]),a[l])*2){
					num++;
				}
			}
		}
	}
	cout<<num;
	return 0;
}