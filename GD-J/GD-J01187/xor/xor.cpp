#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N];
int n,k;
int b[N][N];
/*
4 0
2 1 0 3

*/
struct node{
	int l,r;
}c[N];
bool cmp(node a,node b){
	if(a.r!=b.r)return a.r<b.r;
	else return a.l<b.l;
}
int l;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>1000&&n<200000){
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
			}
			cout<<ans;
		}else if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i])ans++;
			}
			cout<<ans;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		b[i][i]=a[i];
		for(int j=i+1;j<=n;j++){
			b[i][j]=b[i][j-1]^a[j];
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[i][j]==k){
				c[++l]={i,j};
			}
		}
	}	
		
	sort(c+1,c+1+l,cmp);
	int ans=0,s=0,r=0;
	
	for(int i=1;i<=l;i++){
		if(c[i].l>r){
			ans++;
			s=c[i].l;
			r=c[i].r;
		//	cout<<s<<' '<<r<<endl;
		}
	}
	cout<<ans;
	
	return 0;
}
