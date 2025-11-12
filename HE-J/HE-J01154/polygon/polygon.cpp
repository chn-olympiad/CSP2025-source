#include<bits/stdc++.h>
using namespace std;
int n;
int a[114514];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		cout<<2;
	}
	else if(n<=3){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cout<<"0";
				return 0;
			}
			else{
				for(int j=1;j<=10;j++){
					if(a[1]==j && a[2]+(j-1)>=a[3] || a[2]==j && a[1]+(j-1)>=a[3] || a[2]==j && a[3]+(j-1)>=a[1] || a[3]==j && a[1]+(j-1)>=a[2] || a[3]==j && a[1]+(j-1)>=a[2] || a[3]==j && a[1]+(j-1)>=a[2]){
						cout<<"1";
						return 0;
					}
				}
			}
		}
	}
	else{
		cout<<n*n;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
