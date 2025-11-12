#include<bits/stdc++.h>
using namespace std;
int n,k,x,s,num[3000009],ans;
vector<int> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	v.push_back(0);num[0]++;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);s^=x;
		if(num[s^k]>0){
			ans++;for(auto x:v)num[x]=0;
			v.clear();
		}
		num[s]++,v.push_back(s);
	}
	printf("%d\n",ans);
}