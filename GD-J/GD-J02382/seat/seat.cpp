#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[11111],amr,ansh,ansl,ix;
bool cmp(int s1,int s2){
	return s1>s2;
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;for(int i=0;i<n*m;i++)cin>>a[i];amr=a[0];
	sort(a,a+n*m,cmp);
	for(int i=1,k=0;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++,k++){
				if(a[k]==amr){
					cout<<i<<' '<<j;return 0;
				}
			}
		}
		else {
			for(int j=n;j>=1;j--,k++){
				if(a[k]==amr){
					cout<<i<<' '<<j;return 0;
				}
			}
		}
	}
	return 0;
} 
