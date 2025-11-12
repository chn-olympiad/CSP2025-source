#include<bits/stdc++.h>
using namespace std;
int n,m,R;
int a[105]; 
int pai[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)R=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int i=0,j=1,k=1,kk=n,l=1;
	while(j<=m){
		if(j&1) k=1,kk=n;
		else k=-1,kk=1;
		i+=k;
		pai[i][j]=a[l++];
		if(pai[i][j]==R){
			cout<<j<<" "<<i<<endl;
			break;
		}
		if(i==kk) 
		{
			j++;	
			pai[i][j]=a[l++];
			if(pai[i][j]==R){
				cout<<j<<" "<<i<<endl;
				break;
			}
		}
	}
	return 0;
} 
