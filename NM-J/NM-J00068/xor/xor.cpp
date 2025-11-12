#include<bits/stdc++.h>
using namespace std;
	struct x{
		int l,r;
	};
	
	
	bool cmp(x a,x b){
		if(a.l!=b.l){
			return a.r<b.r;
		}
		return a.l>b.l;
	}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long long n,k;
	
	cin>>n>>k;
	
	unsigned int a[500009]={0};
	x s[10000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[j]^a[i-1])==k){
				cnt++;
				s[cnt].l=i;
				s[cnt].r=j;
			}	
			
		}
	}	
		
	
	sort(s+1,s+cnt+1,cmp);
	int sum=0;
	int f=0;
	for(int i=1;i<=cnt;i++){
		if(s[i].l>sum){
			sum=s[i].r;
			f++;
		}
		
	}	
	
	cout<<f;
	fclose(stdin);
	fclose(stdout);

	return 0;
	
}
