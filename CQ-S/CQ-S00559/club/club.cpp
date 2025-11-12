#include <bits/stdc++.h>
using namespace std;
const int maxn=210;
typedef struct _node{
	int a1;
	int a2;
	int a3;
}node;
node a[maxn];
long long t,n;
int q=0;
void dfs(int arr,int k1,int k2,int k3,int max1){
	if(arr>n){
		q=max(q,max1);
		return;
	}
	for(int i=arr;i<=n;i++){
		if(k1<n/2 && (a[i].a1>a[i].a2 || a[i].a1>a[i].a3)){
			dfs(i+1,k1+1,k2,k3,max1+a[i].a1);
		}
		if(k2<n/2 && (a[i].a2>a[i].a1 || a[i].a2>a[i].a3)){
			dfs(i+1,k1,k2+1,k3,max1+a[i].a2);
		}
		if(k3<n/2 && (a[i].a3>a[i].a2 || a[i].a1>a[i].a3)){
			dfs(i+1,k1,k2,k3+1,max1+a[i].a3);
		}
	}
	return;
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		q=0;
		cin>>n;
		if(n<=200){
			memset(a,0,sizeof(a));
			for(int i=1;i<=n;i++){
				cin>>a[i].a1>>a[i].a2>>a[i].a3;
			}
			dfs(1,0,0,0,0);
			cout<<q<<endl;
		}
		else{
			memset(a,0,sizeof(a));
			int op[20009]={0};
			for(int i=1;i<=n;i++){
				cin>>a[i].a1>>a[i].a2>>a[i].a3;
				op[a[i].a1]++;
			}
			int h=0;
			for(int i=20009;i>=0;i--){
				if(h<n/2){
					h++;
					q+=op[i];
				}
				else{
					break;
				}
			}
			cout<<q<<endl;	
		}
	}
	return 0;
}
