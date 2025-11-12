#include <bits/stdc++.h>
using namespace std;
int n,a[5005],he=0;
long long z=0;
bool cnt(int x,int y){
	return x>y;
}

int main() {
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cnt);
	if(n==3){
		if(a[2]+a[3]>a[1]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		for(int i=1;i<=n;i++){
			he=0;
			for(int j=i+1;j<=n;j++){
				he=a[j];
				for(int l=j+1;l<=n;l++){
					he=a[j]+a[l];	
					for(int k=l+1;k<=n;k++){	
						he+=a[k];
					if(he>a[i]){
						z+=(n-l+1);
						z=z%998%244%353;
						he=0;
						break;
					}
				}
			he=0;
			}
			he=0;
		}
		he=0;	
	}
	he=0;
	cout<<z;
	}
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
