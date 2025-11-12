#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int i=1,j=1,cnt=1;
	while(i<=n && j<=m){
		if(a[cnt]==r){
			cout<<jd<<" "<<i<<endl;
			break;
		}
		if(j%2==1){
			if(i==n){
				j++;
			}else{
				i++;
			}
		}else{
			if(i==1){
				j++;
			}else{
				i--;
			}
		}
		cnt++;
	}
	return 0;
}
