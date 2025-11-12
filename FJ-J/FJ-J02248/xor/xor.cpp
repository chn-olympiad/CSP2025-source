#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000001],ans=0,b[1000001],c[1000001],cnt=0,t[100001];
int an(int x,int y,int d[]){
	int bb=0,cc=0;
	while(x>0){
		b[++bb]=x%2;
		x/=2;
	}
	while(y>0){
		c[++cc]=y%2;
		y/=2;
	}
	for(int i=1;i<=max(cc,bb);i++){
		if(b[i]==0&&c[i]==0){
			d[i]=0;
		}
		else{
			d[i]=1;
		}
	}
	return max(cc,bb);
}
void ef(int l,int r){
	int i;
	int h=0;
	for(i=l;i<=n;i++){
		int s=0,f=1;
		for(int j=i+1;j<=n;j++){
			cnt=an(a[j-1],a[j],t);
		}
		for(int j=cnt;j>0;j--){
			s+=t[i]*pow(2,h);
			h++;
		}
		if(s==k){
			ans++;
			l=i+1;
			break;
		} 
	}
	if(i>=n){
		return;
	}
	return ef(l,n);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ef(1,n);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
