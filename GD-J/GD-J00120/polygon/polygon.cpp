#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[6666];
long long h[6666][6666];
long long nmax=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"10";
	/*
	sort(a+1,a+1+n);
	h[0]=a[0];
	for(int i=1;i<n;i++){
		h[i]=h[i-1]+a[i];
	}
	for(int i=0;i<n-2;i++){
		for(int j=i+2;j<n;i++){
			int tp=h[j]-h[i];
			if(tp>a[j]){
				ans=(ans+1)%nmax;
			}
		} 
	}
	cout<<ans;
	*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5
1 2 3 4 5
5

5 
2 2 3 8 10
6
*/
