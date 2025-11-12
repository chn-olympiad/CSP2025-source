#include<bits/stdc++.h>
using namespace std;
int n,k,a,sum,pre=0,ans=0;
map<int,int> p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a=0;p[0]=1;
	for(int i=2;i<=n+1;i++){
		scanf("%d",&a);
		sum=sum^a;
		if(p.count(sum^k)&&p[sum^k]>=pre){
			ans++;
			//cout<<p[sum^k]<<' '<<i<<endl;
			pre=i;
		}
		p[sum]=i;
	}
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3
*/
