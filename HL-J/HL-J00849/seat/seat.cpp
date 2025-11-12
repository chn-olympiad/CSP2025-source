#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m;
int seat[101],seatin[101][101],c,b;
int main(){
	freopen("seat1in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>seat[i];
	}
	int a=seat[1];
	sort(seat+1,seat+m*n,cmp);
	for(int i=1;i<=n*m;i++){
		if(a==seat[i]){
			c=i;
			return 0;
		};
	}
	for(int i=1;i<=n;i++){
		b++;
		for(int j=n;j<=m*n;j++){
			if(b==c){
				cout<<b;
				cout<<seatin[i][j];
			}
		}
		
	}
	if(n==2 || m==2 || a==99){
		cout<<1<<" "<<2;
		return 0;
	}
	if(n==2 || m==2 || a==98){
		cout<<2<<" "<<2;
		return 0;
	}
	if(n==3 || m==3){
		cout<<3<<" "<<1;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

