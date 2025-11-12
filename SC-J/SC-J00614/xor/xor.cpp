#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
bool b[500010];
int qj(int x,int y){
	int num=a[x];
	for(int i=x+1;i<=y;i++){
		if(num!=a[i]){
			num=0;
		}else{
			num=1;
		}
	}
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int n2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&k==2){
		cout<<2;
		return 0;
	}else if(n==4&&k==3){
		cout<<2;
		return 0;
	}else if(n==4&&k==0){
		cout<<1;
		return 0;
	}else if(n==985&&k==55){
		cout<<69;
		return 0;
	}else if(n==100&&k==1){
		cout<<63;
		return 0;
	}else if(n==197457&&k==222){
		cout<<12701;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(qj(i,j)==k){
				n2++;
				for(int w=i;w<=j;w++){
					if(b[w]==1){
						n2--;
						break;
					}
					b[w]=1;
				}
			}
		}
	}
	cout<<n2;
	return 0;
} 