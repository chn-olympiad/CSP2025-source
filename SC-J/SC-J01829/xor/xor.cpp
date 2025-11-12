#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],b[500005]={0};
int iii(int aa,int bb){
	int sum=0;
	for(int i=aa;i<=bb;i++){
		sum=sum^a[i];
	}
	return sum;
}	
void jjj(int aa,int bb){
	for(int i=aa;i<=bb;i++){
		b[i]=1;
	}
}
bool check(int ii,int jj){
	for(int i=ii;i<=jj;i++){
		if(b[i]==1){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(iii(i,j)==k&&check(i,j)){
				jjj(i,j);
				maxx++;
			}
		}
	}
	cout<<maxx;
	return 0;
}
