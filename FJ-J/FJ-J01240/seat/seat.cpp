#include<bits/stdc++.h>
using namespace std;
int m,n,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	while(m!=n){
		for(int i;i<=9;i--){
			for(int n;n<=9;n--){
				for(int m;m<=9;m--){
					cout<<n*m;
				}	
			}
		}
	}
	for(int j;j=m;j++){
		j++;
	}	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}












