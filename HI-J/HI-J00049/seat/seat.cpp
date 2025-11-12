#include <bits/stdc++.h>

using namespace std;
int a[15][15];
int r=0;
int mk[100];
int n,m;
bool cmp(int a,int b){
	
	if(a>b)
	{
		return a>b;
		
	}
	else{
		return 0;
	} 
}
int main(){
	//freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	
		cin>>mk[i];
		r=mk[1]; 
	}
	sort(mk+1,mk+n*m,cmp);
	for(int i=1;i<=n;i+=0){
		for(int j=1;i<=m;j++){
			a[i][j]+=mk[j];
			if(j=m) {
				i++;
				continue;
			}
			
		}
		continue;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j+=0){
			a[i][j]+=mk[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		
			if(a[i][j]==r){
				cout<<a[i][j];
			}
		}
	}

	return 0;
}
