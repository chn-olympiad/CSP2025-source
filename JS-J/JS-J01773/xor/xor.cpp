#include <bits/stdc++.h>
using namespace std;
int a[500001],k;
struct u{
	int x;
	int y;
}f[500001];

bool qujian(int l,int r){
	int sum=a[l];
	for(int i=l+1;i<=r;i++){
		sum=sum^a[i];
	}
	if(sum==k){
		return 1;
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<n;i++){
		bool g=false;
		for(int j=i;j<=n;j++){
			if(qujian(i,j)){
				f[i].x=i;
				f[i].y=j;
				g=true;
				break;
			}
		}
		if(!g){
			f[i].y=1000086;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<i;j++){
			if(f[j].y>f[j+1].y){
				swap(f[j],f[j+1]);
			}
		}
	}
	int sum=0,e=0;
	for(int i=1;i<=n;i++){
		if(f[i].y!=1000086){
			if(f[i].x>e){
				e=f[i].y;
				sum++;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
