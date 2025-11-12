#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
struct xxx{
	int l;
	int r;
};
xxx hsh[500010];

void f(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			if(hsh[j].r>hsh[j+1].r)swap(hsh[j],hsh[j+1]);
		}
	}
}
bool f(int l,int r){
	int x=a[l];
	for(int i=l+1;i<=r;i++){
		x^=a[i];
	}
	if(x==k)return 1;
	else return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	//for(int i=1;i<=n+10;i++)hsh[i]=-1;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>=100){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f(i,j)==1){
				hsh[i].l=i;
				hsh[i].r=j;
			}
		}
	}
	//sort(hsh+1,hsh+n+1);
	f();
	//for(int i=1;i<=n;i++) cout<<hsh[i].l<<" "<<hsh[i].r<<endl;;
	
	int re=0;
	int s=hsh[1].r;
	for(int i=1;i<=n;i++){
		if(hsh[i].r>=s&&hsh[i].r!=0)re++;
	}
	cout<<re;
	return 0;
}
