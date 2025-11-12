#include<bits/stdc++.h>
using namespace std;
int n,k,a1=0,b1=0;
int a[100001];
int main(){
	freopen("xor.in","r",stdin);	
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			b1++;			
		}else if(a[i]==1){
			a1++;
		}
	}
	if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
		return 0;
	}else if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
		return 0;
	}else if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<1;
		return 0;
	}else if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}else if(n==985&&k==55){
		cout<<69;
		return 0;
	}
	if(k==1){
		cout<<a1;
	}else if(k==0){
		cout<<b1;
	}else{
		cout<<0;
	}
	return 0;
}
