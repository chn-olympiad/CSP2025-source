#include<bits/stdc++.h>
using namespace std;
int a[10001][10001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m=3;
	int t;
    cin>>t;
    int n;
    int cnt=0;
    while(t--){
    for(int i=1;i<=n;i++){
    	if(n%2==0) cin>>n;
    	cin>>a[i][1]>>a[i][2]>>a[i][3];
    	for(int j=1;j<=n;j++){
        int p=0;
        if(a[i][j]>a[i][p]&&a[j]<n/2);
    	    a[p]=a[j];
	    }a[p++];
	    for(int j=1;j<=n;j++){
        int f=0;
        if(a[i][j]>a[i][f]&&a[j]<n/2);
    	    a[f]=a[j];
	    }a[f++];
	    for(int j=1;j<=n;j++){
        int g=0;
        if(a[i][j]>a[i][g]&&a[j]<n/2);
    	    a[g]=a[j];
	        }a[g++];
	    }
	}
    cout<<max(p+f+g)<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
