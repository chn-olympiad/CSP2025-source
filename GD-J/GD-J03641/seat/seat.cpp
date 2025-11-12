#include<bits/stdc++.h>
using namespace std;
struct node{
	int sco;
	bool ming;
}a[110];
bool cmp(node a,node b){
	return a.sco>b.sco;
}
int n,m,nm; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	a[1].ming=1;
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++)cin>>a[i].sco;
	sort(a+1,a+nm+1,cmp);
	if(n==1){
		for(int i=1;i<=nm;i++){
			if(a[i].ming==1){
				cout<<1<<' '<<i;
			}
		}
	}else{
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(j%2==1){
					if(a[j*n+i-n].ming==1){
						cout<<j<<' '<<i;
					} 	
				}else{
					if(a[j*n+i-n].ming==1){
						cout<<j<<' '<<n-i+1;
					} 
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
