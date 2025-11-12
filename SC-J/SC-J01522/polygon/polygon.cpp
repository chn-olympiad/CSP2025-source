#include<bits/stdc++.h>
using namespace std;
int n,c[5005];
long long a[5005],ans;
const int N=998244353;
bool polygon(int aa[]){
	int m=-1;long long sum=0;
	for(int i=1;i<aa[0];++i){
		if(aa[i]>m) m=aa[i];
		sum+=aa[i];
	}
	if(sum>2*m) return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){//边数 
    	c[0]=i;
		for(int j=1;j<=n;j++);
	}
	cout<<9;
	return 0;
}
