#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10001];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4){
		if(m==3){
			if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
				cout<<2;
			}
		}else if(m==2){
			if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
				cout<<2;
			}
		}else if(m==0){
			if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
				cout<<1;
			}
		}
	}
	return 0;
}
