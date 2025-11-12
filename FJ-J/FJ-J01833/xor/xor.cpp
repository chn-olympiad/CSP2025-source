#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}b[500001];
int n,k;
int a[500001];
bool cmp(node a,node b){
	if(a.r!=b.r){
		return a.r<b.r;
	}else{
		return a.l>b.l;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=a[i];
			if(i==j){
				cnt=a[j];
			}else{
				for(int k=i;k<=j;k++){
					cnt=cnt^a[k];
				}
			}
			if(cnt==k){
				num++;
				b[num].l=i;
				b[num].r=j;
			}
		}
	}
	sort(b+1,b+1+num,cmp);
	int ans=1;
	for(int i=2;i<=num;i++){
		if(b[i].l>=b[i-1].r&&b[i-1].l>b[i].l){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
  return 0;
}
