#include<bits/stdc++.h>
using namespace std;
int a[110]={};
int s[110][110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=m*n;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	int mark=a[1];
	sort(a,a+1+x,cmp);
	int tmp=0;
    for(int i=1;i<=m;i++){
    	if(i%2!=0){
    		for(int j=1;j<=n;j++){
    			s[i][j] = a[tmp];
    			tmp++;
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
    			s[i][j] = a[tmp];
    			tmp++;
			}
		}
	}
	for(int j=1;j<=m+1;j++){
		for(int i=1;i<=n+1;i++){
			if(s[i][j]==mark){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	return 0;
}
