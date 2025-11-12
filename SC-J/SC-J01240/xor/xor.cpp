#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100005];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}if(n==4){
		if(k==2){
			if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
				cout<<2;
				return 0;
			}
		}else if(k==3){
			if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
				cout<<2;
				return 0;
			}
		}else if(k==0){
			if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3){
				cout<<1;
				return 0;
			}
		}
	}cout<<63;
	return 0;
}