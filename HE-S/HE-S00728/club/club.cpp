#include<bits/stdc++.h>
using namespace std;
int asum[100050];
int jieguo[6];
int main(){
	freopen("club.in ","r",stdin);
	freopen("club.out","w"stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int amax=n/2;
		int a1,a2,a3;
		int a1sum=0;
		for(int i=1;i<=n;i++){
			cin>>a1>>a2>>a3;
			asum[i]=a1;
		}
		sort(asum,asum+n);
		for(int i=0;i<amax;i++){
			a1sum+=asum[i];
		}
		jieguo[t]=a1sum;
	}
	for(int i=t;i>0;i--){
		cout<<jieguo[i]<<endl;
	}
	return 0;
}
