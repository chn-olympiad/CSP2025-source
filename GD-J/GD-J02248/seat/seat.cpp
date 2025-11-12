#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[1010];
int tar;
int cnt;
int tn;
int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	tar=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==tar){
			cnt=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
//				cout<<tn<<" "<<cnt<<endl;
				tn++;
				if(tn==cnt){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
//				cout<<tn<<" "<<cnt<<endl;
				tn++;
				if(tn==cnt){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

