#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m);
	int j=0;
	for(int i=n*m;i>=1;i--){
		j++;
		if(a[i]==t){
			int s=(j)/n;
			//cout<<s<<endl;
			if(s%2==1){
				cout<<(j-n*s+1)<<' '<<(s+1)<<endl;
				return 0;
			}
			if(s%2==0){
				cout<<(n-j+n*s-1)<<' '<<(s+1)<<endl;
				return 0;
			}
		}
	}
	return 0;
}//491距离考试结束：00:49:07 CSP-J2025：