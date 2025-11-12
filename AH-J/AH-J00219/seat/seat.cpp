#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int cj=n*m;
	for(int i=1;i<=cj;i++){
		cin>>a[i];
	}
	int cmp=a[1];
	int ct=1;
	sort(a+1,a+cj+1);
	for(int i=m;i>=1;i--){
		if(i%2==0){
			for(int k=1;k<=n;k++){
				if(a[ct]==cmp){
					cout<<i<<" "<<k<<endl;
					return 0;
				}else{
					ct++;
				}
			}
		}else{
			for(int k=n;k>=1;k--){
				if(a[ct]==cmp){
					cout<<i<<" "<<k<<endl;
					return 0;
				}else{
					ct++;
				}
			}
		}
	}
	return 0;
}
