#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1 ; i <= n*m ; ++i){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	//
//	for(int i = 1 ; i <= n*m ; ++i)
//		cout<<a[i]<<" ";
	//
	int pos=1;
	for(int i = 1 ; i <= n ; ++i){
		if(i%2==1){
			for(int j = 1 ; j <= m ; ++j){
				if(a[pos]==r){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				++pos;
			}
		}else{
			for(int j = 1 ; j <= m ; ++j){
				if(a[pos]==r){
					cout<<i<<" "<<m-j+1<<endl;
					return 0;
				}
				++pos;
			}
		} 
	}
	return 0;
}
