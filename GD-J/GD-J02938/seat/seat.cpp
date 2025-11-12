#include<bits/stdc++.h>
using namespace std;
int m,n,a[11][11],s[110];
bool c(int x,int y){
	return x>y;
}
int main(){
	int l=1,num;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	num=s[1];
	sort(s+1,s+n*m+1,c);
	for(int i=1;i<=n*m;i++){
		if(num==s[i]){
			num=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[j][i]=l;
				l++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				a[j][i]=l;
				l++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==num){
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
