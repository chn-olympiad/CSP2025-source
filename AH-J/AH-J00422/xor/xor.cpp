#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int k,n,a[110],he=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				he++;
			}
			cout<<he;
			return 0;
		}
	}else if(n==2){
		if(a[1]+a[2]==0){
			cout<<"2";
			return 0;
		}else if(a[1]==0||a[2]==0){
			cout<<"1";
			return 0;
		}else if(a[1]!=0&&a[2]!=0){
			cout<<"0";
			return 0;
		}
	}
			
		
    return 0;
}
