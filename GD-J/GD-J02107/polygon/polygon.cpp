#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,a[5005],b[5005];
void pai(int x,int shu,int anss,int N){
	for(int i=x+1;i<=n;i++){
		if(shu<N){
			pai(i,shu+1,anss+a[i],N);
		}
		else{
			
			if(anss>a[i]){
				cout<<anss+a[i]<<endl;
				ans++;
			}
		}
	} 
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1+i;j<=n;j++){
			if(a[i]>a[j])swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		pai(0,1,0,i);
	}
	cout<<ans%998244353;
	return 0;  
}


