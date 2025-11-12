#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[110][110],p=1,f;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];

	}
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[p];
				if(a[p]==f){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
				p++;
				
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[p];
				if(a[p]==f){
					cout<<i<<" "<<j<<endl;
					return 0;
				}				
				p++;
			}
		}
	}

	return 0;
} 
