#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k;
int f(int num,int mi,int su){
	int s=0;
	for(int i=mi;i<=n;++i){
		if(mi%2==0){
			int sum=0;
			for(int j=mi;j<=i;++j)sum+=a[j];
			if(sum%k==0)s=max(s,f(num+1,i+1,su+1));
		}else{
			s=max(s,f(num,i,su));
		}
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	cout<<f(1,0,0);
	return 0;
}
