#include<bits/stdc++.h>
using namespace std;
int n,a[5500],cnt,i,j,k,l1=-1,r1,ma,t;
void f(int l,int r){
	t=0;
	for(int i=l;i<=r;i++){
		t=t^a[i];
	}
	if(t==k&&l<r){
		if(l1==-1){
			l1=l,r1=r,cnt++;
			return;
		}
		if((r<=r1&&r>=l1)||(l<=r1&&l>=l1)) return;
		cout<<l<<' '<<r<<endl;
		cnt++;
	}
	return;
}
int main(){
	int m,z;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int v=0;v<n;v++){
		cin>>a[v];
	}
	if(k==0){
		for(int i=0;i<n;i++){
			if(a[i]==k) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			f(i,j);
		}
	}
	cout<<cnt;
	return 0;
}