#include<bits/stdc++.h>
using namespace std;
int n,m,js,s,a[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;++i){
		cin>>a[i];
	}
	s=a[0];
	if(s==100){
		cout<<1<<" "<<1;
		return 0;
	}
	if(s==1){
		cout<<m<<" "<<n;
		return 0;
	}
	js=n*m;
	sort(a,a+js);
	for(int i=0;i<js;++i){
		if(s==a[i]){
			s=i;
			break;
		}
	}
	for(int i=0;i<m;++i){
		if(i%2==1){
			for(int j=n-1;j>=0;--j){
				js--;
				if(js==s){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
		if(i%2==0){
			for(int j=0;j<n;++j){
				js--;
				if(js==s){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
