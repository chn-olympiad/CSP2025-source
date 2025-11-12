#include<bits/stdc++.h>
using namespace std;
const int m=1e7+10;
struct node{
	int L,R;
	bool id=0;
}an[m];
bool cmp(node a,node b){
	return a.L<b.L;
}
int a[m],s[m];
int main(){
	freopen("xor6.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=a[i]^s[i-1];
	}int sum=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int x=s[r]^s[l-1];
			if(x==k){
				an[++sum]={l,r};
			}
		}
	}sort(an+1,an+sum+1,cmp);
	int ans=sum;
	for(int i=2;i<=sum;i++){
		if(an[i].L<=an[i-1].R){
			ans--;
		}
	}cout<<ans;
	return 0;
}
