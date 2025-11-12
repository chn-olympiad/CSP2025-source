#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[110]={0};
int s[11][11]={0};

bool cmp(int x,int y){
	if(x>y){
		return true;
	}
	
	return false;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	
	int r_score=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	int p=1;
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			s[j][i]=a[p];
			p++;
		}
		for(int j=n;j>0;j--){
			s[j][i+1]=a[p];
			p++;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==r_score){
				cout<<j<<" "<<i;
			}
		}
	}
	


	fclose(stdin);
	fclose(stdout);
	
	return 0;
}