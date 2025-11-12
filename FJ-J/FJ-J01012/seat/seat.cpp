#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int a[110];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int po=a[1];
	sort(a+1,a+n*m+1,cmp);
	int j=0,k=1;
	for(int i=1;i<=n*m;i++){
		if(k%2==1){
			j++;
			if(j>n){
				j--;
				k++;
			}
		}else if(k%2==0){
			j--;
			if(j<1){
				j++;
				k++;
			}
		}
		if(a[i]==po){
			cout<<k<<" "<<j;
			return 0;
		}
	
	}
	return 0;	
}
