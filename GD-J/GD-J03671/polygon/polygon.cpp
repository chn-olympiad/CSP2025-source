#include<bits/stdc++.h>
using namespace std;

int s;
int a[100000];
long sum,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>s;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	sort(a+1,a+s+1);
	for(int i=1;i<=s;i++){
		sum=0;
		for(int j=i;j<=s;j++){
			sum+=a[j];
			if(j>=3){
				if(sum>a[j]*2){
					ans++;
					ans%=998244353;
				}
			}
		}
		
	}
	cout<<ans;
	return 0;
}
