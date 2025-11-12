#include<bits/stdc++.h>
using namespace std;
int a[110];
int w[12][12];
int nf;
bool o(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			nf=a[i];
		}
	}
	sort(a+1,a+n*m+1,o);
	int num=1;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int i1=m;i1>=1;i1--){
				if(a[num]==nf){
					cout<<i<<" "<<i1;
					return 0;
				}
				num++;
			}
		}
		else{
			for(int i1=1;i1<=m;i1++){
				if(a[num]==nf){
					cout<<i<<" "<<i1;
					return 0;
				}
				num++;
			}
		}
	}
	return 0;
}

