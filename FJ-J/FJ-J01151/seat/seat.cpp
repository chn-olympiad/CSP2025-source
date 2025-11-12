#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,chengji;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	chengji=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==chengji){
			int ansl=(i+n-1)/n,ansh;
			cout<<ansl<<" ";
			if(ansl%2==1){
				ansh=i%n;
				if(ansh==0){
					ansh=n;
				}
			}else{
				ansh=n-i%n+1;
				if(ansh==n+1){
					ansh=1;
				}
			}
			cout<<ansh;
			break;
		}
	}
	return 0;
} 
