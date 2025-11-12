#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int R;
int s[15][15];
bool cmp(int x,int y){
	return x>y;
}
/*
  4 5
  5 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
  4 5
  5 1 2 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
  * 
    2 2
 98 99 100 97
  3 3
 94 95 96 97 98 99 100 93 92
*/
int l=1,id;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>R;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	a[1]=R;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			id=i;
			break;
		}
	}
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				s[i][j]=l;
				l++;
		    }
		}else{
			for(int i=n;i>=1;i--){
			    s[i][j]=l;
				l++;
		    }
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==id){
				cout<<j<<' '<<i;
				return 0;
			}
	    }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
