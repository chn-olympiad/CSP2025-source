#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100],b,c;
	cin>>n>>m;
	c=n*m;
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}	
	b=a[1];
	sort(a+1,a+c+1);
	int k=c;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(a[k]==b){
					cout<<j<<' '<<i;
					return 0;
				}
				k--;
			}
		}else{
			for(int i=n;i>=1;i--){
				if(a[k]==b){
					cout<<j<<' '<<i;
					return 0;
				}
				k--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
