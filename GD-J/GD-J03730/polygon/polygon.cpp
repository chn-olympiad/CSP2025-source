#include<bits/stdc++.h>
using namespace std;
const int M=1000;
int n,ans,max,sum;
int a[M];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<1<<n;i++) {
		int sum=0;
		int max=0;
		for(int j=0;j<=n;j++){
			int w=1<<j;
			if(i&w){
				max=a[j+1]>max?a[j+1]:max;
				sum+=a[j+1];
			}
		}
		if(sum>2*max) ans++;
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
