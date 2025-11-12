#include<bits/stdc++.h>
using namespace std;
int main(){
	//feropen("polygon.in","r",stdin);
	//feropen("polygon.out","w",stdout);
	int n;
	long long num=0,sum=0;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a.begin(),a.end());
	if(sum-a[n]>a[n])num++;
	for(int bj=n;bj>=3;bj--){
		for(int k=1;k<=bj-2;k++){
			for(int i=k;i<=bj;i++){
				for(int j=i;j<=bj;j++){
					for(int z=i;z<=j;z++){
						sum-=a[z];
					}
					if((sum-a[bj])>a[bj])num++;
					for(int z=i;z<=j;z++){
						sum+=a[z];
					}
				}
			}
			sum-=a[k];
		}
		sum-=a[bj];
	}
	cout<<num%998244353;
	return 0;
}
