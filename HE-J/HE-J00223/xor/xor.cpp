#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,k,cnt=0;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k) res=0,cnt++;
		else{
			res=res^a[i];
			if(res==k) res=0,cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}

