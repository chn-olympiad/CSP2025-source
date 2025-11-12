#include<bits/stdc++.h>
using namespace std;
int t;
int cmp(int a,int b){
	return a>b;
}
int a[3][100005]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		
		for(int i=1;i<=n;i++){
        cin>>a[0][i]>>a[1][i]>>a[2][i];}
        sort(a[0]+1,a[0]+n+1,cmp);
        int ans=n/2;
        int fina=0;
        int g=0;
        while(ans--){
        	g++;
  //      	cout<<a[0][g]<<" ";
        	fina+=a[0][g];
        	
		}
		cout<<fina<<endl;fina=0;
	}
	return 0;
} 
