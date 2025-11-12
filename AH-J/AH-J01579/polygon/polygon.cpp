#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int q=1;q<=n;q++){
		for(int w=1;w<=n;w++){
			for(int e=1;e<=n;e++){
				if(a[q]+a[w]+a[e]>max(max(a[q],a[w]),max(a[w],a[e]))&&q!=w&&w!=e){
					sum++;
				}
			}
		}
	}
	cout<<sum%998244353;
return 0;
}
