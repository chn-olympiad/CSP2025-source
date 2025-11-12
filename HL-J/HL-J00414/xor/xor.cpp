#include <bits/stdc++.h>
using namespace std;
int a[500009],n;
struct node{
	int a,b;
}chs[500009];
long long k;
bool xor1(int l,int r){
	int sum=0;
	for(int i=l;i<=r;i++){
		sum^=a[i];
	}
	return sum==k;
}
bool cmp(node a,node b){
	return a.b<b.b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int maxn=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(xor1(i,j)){
				chs[maxn].a=i;
				chs[maxn++].b=j;
				break;
			}
		}
	}
	sort(chs,chs+maxn-1,cmp);
	int cnt=0;
	int last=-1;
	for(int i=0;i<maxn-1;i++){
		if(chs[i].a>last){
			cnt++;
			last=chs[i].b;
		}
	}
	cout<<cnt;
	return 0;
} 
