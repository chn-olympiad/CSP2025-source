#include<bits/stdc++.h>
using namespace std;
int n;long long sum=0;
int b1;
struct re{
	int a1;
	int a2;
	int a3;
};

bool f(re a,re b){
	return a.a1>b.a1;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		re r[n];sum=0;b1=n/2;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&r[i].a1,&r[i].a2,&r[i].a3);
		}
		sort(r,r+n,f);
		for(int i=0;i<n and b1--;i++){
			sum+=r[i].a1;
		}
		printf("%lld\n",sum);
	}
	
	
	return 0;
}
