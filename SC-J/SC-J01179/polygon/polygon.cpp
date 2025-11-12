#include<bits/stdc++.h>
using namespace std;
int n,a[5555],ans=0;
vector<int> b(5555,0);
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		b[i]+=a[i];
		if(i!=0){
			b[i]+=b[i-1];
		}
	}
	for(int i=2;i<n;i++){
		for(int j=i;j<n;j++){
			if(j!=i){
				if(b[j]-b[j-i-1]>a[j]*2){
					ans++;
				}
			}else{
				if(b[j]>a[j]*2){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 