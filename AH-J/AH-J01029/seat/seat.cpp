#include<bits/stdc++.h>
using namespace std;
int m,n,a[110],s,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=m*n;
	for(int q=1;q<=s;q++){
		cin>>a[q];
	}
	d=a[1];
	for(int q=1;q<=s;q++){
		for(int w=1;w<=s-q;w++){
			if(a[w]<a[w+1]){
				int l=a[w];
				a[w]=a[w+1];
				a[w+1]=l;
			}
		}
		
	}
	for(int q=1;q<=n;q++){
		if(q%2==1){
			int x=(q-1)*m;
			for(int w=1;w<=m;w++){
				if(a[x+w]==d){
					cout<<q<<" "<<w;
					return 0;
				}
			}
		}else{
			int x=(q-1)*m;
			for(int w=m;w>=1;w--){
				if(a[x+m-w+1]==d){
					cout<<q<<" "<<w;
					return 0;
				}
			}
		}
	}
			
	return 0;
}
