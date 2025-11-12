#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int a[5005];
int vis[5005];
int r[5000],count,n,b=0;
int how(int r[5005],int s,int b){
	if(b==s){
		for(int i=0;i<s;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		b=0;
	}
	for(int i=1;i<=n;i++){
		if(vis[a[j]]==0){
			r[b]=a[j];
			b++;
			vis[a[j]]=1;
			how(r,s,b);
			vis[a[j]]=0;
		}
	}

}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	how(r,3,b);
	return 0;
} 