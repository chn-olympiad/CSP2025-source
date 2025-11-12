#include<bits/stdc++.h>
using namespace std;
int c[105];
int a[105][105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("set.in","r",stdin);
    freopen("set.out","w",stdout);
    int n,m,f=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>c[i];
	}
	int s=c[1];
	sort(c+1,c+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
			    a[j][i]=c[f];
			    f++;
		    }
		}else{
			for(int j=1;j<=n;j++){
			    a[j][i]=c[f];
			    f++;
		    }
		}
	}
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		if(a[i][j]==s){
    			cout<<j<<" "<<i;
			}
		}
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
