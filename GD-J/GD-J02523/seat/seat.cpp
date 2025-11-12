#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int R=a[0];
	sort(a,a+n*m);
//	for(int i=0;i<n*m;i++){
//		cout<<a[i]<<' ';
//	}
	int cnt=n*m-2;
	c=1;r=1;
	if(a[cnt+1]==R){
		cout<<1<<' '<<1<<endl;
		return 0;
	}
	while(cnt>=0){
		if(c%2==1){
			if(r<n){
				r++;
			}else{
				c++;
			}
		}else{
			if(r>1){
				r--;
			}else{
				c++;
			}
		}
//		cout<<a[cnt]<<' '<<R<<endl;
		if(a[cnt]==R){
			cout<<c<<' '<<r<<endl;
			break;
		}
		cnt--;
	}
	return 0; 
} 
