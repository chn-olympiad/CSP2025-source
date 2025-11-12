#include <bits/stdc++.h>
using namespace std;
int n,a[10005][3]={0},q=0,b=0,f;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>f;
	for(int x=1;x<=f;x++){
		cin>>n;b=0;
		for(int i=1;i<=n;i++){
			q=0;
			for(int j=1;j<=3;j++){
				a[i][0]=0;
				cin>>a[i][j];
				if(a[i][j]>a[i][j-1]){
					q=a[i][j];
				}
				else{
					a[i][j]=q;
				}
			}
			b+=q;
		}
		cout<<b<<endl;
	}
}
