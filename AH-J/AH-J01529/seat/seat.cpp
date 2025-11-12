#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int b[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,d;
	cin>>c>>d;
	for(int i=1;i<=c*d;i++){
		cin>>b[i];
	}
	int o=b[1];
	sort(b+1,b+c*d+1);
	int p=c*d,s=0;
	for(int i=1;i<=c;i++){
		s++;
		if(s%2){
			for(int j=1;j<=d;j++){
				a[j][i]=b[p--];
			}
		}
		else{
			for(int j=d;j>=1;j--){
				a[j][i]=b[p--];
			}
		}
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=d;j++){
			if(a[i][j]==o){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
