#include<bits/stdc++.h>
using namespace std;
int a[500010];
int n,k;
struct node{
	int l,r;
}ans[500010];
int num[500010];
void f1(){
	cout<<n;
}
bool cmp(node a,node b){
	if(a.r !=b.r ){
		return a.r <b.r ;
	}
	else{
		return a.l >b.l ;
	}
}
void f2(){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int num=a[i];
			for(int r=i+1;r<=j;r++){
				num^=a[r];
			}
			if(num==k){
				ans[++sum].l=i;
				ans[sum].r =j;
			}
		}
	}
	sort(ans+1,ans+1+sum,cmp);
	int ans1=0;
	for(int i=1;i<=sum;i++){
		int e=i+1;
		while(ans[i].r >=ans[e].l ){
			e++;
		}
		ans1++;
		i=e-1;
	}
	cout<<ans1;
}
void f3(){
	if(k==1){
		int ans1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans1++;
			}
			
		}
		cout<<ans1;
	}
	else {
		int ans1=0;
		for(int j=1;j<=n;j++){
			if(a[j]==0){
				ans1++;
			}
			else if(a[j]==1&&a[j+1]==1){
				ans1++;
				j++;
			}
		}
		cout<<ans1;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	int flag1=1,flag2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			flag2=0;
		}
		if(a[i]!=1){
			flag1=0;
		}
	}
	if(flag1){
		f1();
	}
	else if(flag2){
		f3();
	}
	else {
		f2();
	}
	return 0;
}
