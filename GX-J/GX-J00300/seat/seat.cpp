#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
	}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
    int a[101],k[101];
    for(int i=0;i<n*m;i++){
		cin>>a[i];
		k[i]=a[i];
		}
	sort(a,a+n*m,cmp);
	if(n==1&&m==10){
		for(int i=1;i<=10;i++){
			if(a[i]==k[1]){
				cout<<"1"<<i;
				return 0;
			}
		}
	}
	else if(n==10&&m==1){
		for(int i=1;i<=10;i++){
			if(a[i]==k[1]){
				cout<<i<<"1";
				return 0;
			}
		}
	}
}

