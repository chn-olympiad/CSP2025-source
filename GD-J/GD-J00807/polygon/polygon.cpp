#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const int maxn=1e8+5;
ll n,a[5005],sum,k,v;
/*void dfs(int f,int t,int q){
	for(int i=q;i<n;i++){
		t++;
		b[v]=a[i];
		v++;
		if(t==f){
			for(int j=0;j<f;j++)cout<<b[j]<<" ";
			cout<<endl;
			sum++; 
			v--;
			dfs(f,t-1,i+1);
		}
	}
	return;
}*/
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(a[0]+a[1]+a[2]>2*(max(max(a[0],a[1]),a[2]))){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	cout<<sum;
	return 0;
} 
