#include<iostream>
#include<stdio.h>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;
int a[500005];
struct str{
	int b,e;
};
bool cmp(str xx,str yy){
	return xx.e<yy.e;
}
vector<str>v;
long long ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%d",&a[1]);
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=a[i-1]^a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[j]^a[i])==k){
				str b1;
				b1.b=i+1;
				b1.e=j;
				v.push_back(b1);
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	if(!v.empty()&&v.size()>=2){
	ans++;
	auto it=v.begin();
	long long lse=it->e;
	it++;
	for(;it!=v.end();it++){
		if(it->b>lse){
			ans++;
			lse=it->e;
		}
	}
	printf("%lld",ans);
	}
	else if(v.empty()){
		printf("0");
	}
	else if(v.size()==1){
		printf("1");
	}
	return 0;
}
