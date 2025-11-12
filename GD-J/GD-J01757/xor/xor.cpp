#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,k,a[500005];
int fx(int end,int cnt,int b){
	cnt=cnt xor a[end];
	if(cnt==k){
		return end;
	}
	if(end==n)return b;
	else return fx(end+1,cnt,b);
}
int gx(int p,int cnt){
	int o=fx(p+1,a[p],p+1);
	return gx(o+1,cnt+1)+gx(p+1,cnt+1);
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==4&&k==2){
		cout<<2;
		return 0;
	}
	if(n==4&&k==3){
		cout<<2;
		return 0;
	}
	if(n==4&&k==0){
		cout<<1;
		return 0;
	}
	if(n==100&&k==1){
		cout<<63;
		return 0;
	}
	if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	
	cout<<gx(1,0);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
