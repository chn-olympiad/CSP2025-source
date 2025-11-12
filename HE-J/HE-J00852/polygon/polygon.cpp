#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],s;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}

	for(int i=0;i<=n-3;i++){
		for(int j=i+3;j<=n;j++){
			if(j-i<3) break;
			if(b[j]-b[i]>a[j]+a[j]){
				s++;
			}else if(b[j]-a[i]>a[j]+a[i]) s++;
			s=s%998244353;
		}
	}
	cout<<s;
	 fclose(stdin);
	 fclose(stdout);
	return 0;
}


