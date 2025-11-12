#include<bits/stdc++.h>
using namespace std;
struct node{
	int st,nd,rd,used;
}a[100001];
bool cmp1(node a,node b){
	return a.st>b.st;
}
bool cmp2(node a,node b){
	return a.nd>b.nd;
}
bool cmp3(node a,node b){
	return a.rd>b.rd;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		int sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].st>>a[i].nd>>a[i].rd;
			a[i].used=0;
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(a[i].st>=a[i].nd&&a[i].st>=a[i].rd&&a[i].used==0){
				a[i].used=1;
				sum+=a[i].st;
			}
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(a[i].nd>=a[i].st&&a[i].nd>=a[i].rd&&a[i].used==0){
				a[i].used=1;
				sum+=a[i].nd;
			}
		}
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(a[i].rd>=a[i].nd&&a[i].rd>=a[i].st&&a[i].used==0){
				a[i].used=1;
				sum+=a[i].rd;
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
