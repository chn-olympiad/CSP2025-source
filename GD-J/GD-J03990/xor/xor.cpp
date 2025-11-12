#include<bits/stdc++.h>
using namespace std;
int a[500001];
int ww[101],w[101];
struct node{
	int l,r;
}t[100010];
int cnt=0,now=1;
bool cmp(node a,node b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int i=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		if(x==k){
			t[now].l=i;
			t[now].r=i;
			now++;
		}
		for(int j=i+1;j<=n;j++){
			x=x^a[j];
			if(x==k){
				t[now].l=i;
				t[now].r=j;
				now++;
			}
		}
	}
//	cout<<"=============================";
//	for(int i=0;i<now;i++){
//		cout<<t[i].l<<" "<<t[i].r<<endl;
//	}
	sort(t,t+now,cmp);
//	for(int i=1;i<now;i++){
//		cout<<t[i].l<<" "<<t[i].r<<endl;
//	}
	int m=t[1].r;
	cnt++;
	for(int i=2;i<now;i++){
		if(t[i].l>m){
			cnt++;
			m=t[i].r;
		}
	}
	cout<<cnt;
	return 0;
}





