#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	int a[110];
	cin>>n>>m;
	int num=n*m;
	for(int i=1;i<=num;i++) cin>>a[i];
	int g=a[1];
	sort(a+1,a+num+1);
	int i;
	for(int j=n*m;a[j]>=g;j--) i=n*m-j+1;
	int g_m,g_n;
	for(int j=1;;j++){
		if(i-n*j==0){
			g_m=j;
			break;
		}
		else{
			if(i-n*j<n){
				g_m=j+1;
				break;
			}
		}
	}
	if(g_m%2==0) g_n=n-(i-n*(g_m-1))+1;
	else g_n=i-n*(g_m-1);
	if(g_n==0) g_n=n; 
	cout<<g_m<<" "<<g_n; 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	return 0;
}