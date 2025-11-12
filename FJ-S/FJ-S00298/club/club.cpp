#include<bits/stdc++.h>
using namespace std;
int T;
int k=-9999;		
long n;
long long sum;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		sum=0;
		cin>>n;
		int ans[n];
		for(int i=1;i<=n;i++){
			k=0;
			long long a[5];
			for(int i=1;i<=3;i++){
				cin>>a[i];
			} 
			for(int i=1;i<=3;i++){
				if(a[i]>=k) k=a[i];
			}
			sum+=k;

	    }
        cout<<sum;
	}
	return 0;
}
