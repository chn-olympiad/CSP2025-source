//GZ-S00365 贵阳市第一中学 罗李镜 
#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][5]={},s[10]={},b[10][5]={},d[100005][5];
int com(int k,int i){
	int p=1,v=0;
	for(int j=1;j<=3;j++)if(v<a[i][j]){
		v=a[i][j];
		p=j+1;
	}
	b[k][p]++;
	return v;
}
int mxn(int i,int j){
	if(j==3){
		if(a[i][j-1]>a[i][j-2])return a[i][j-1];
		else return a[i][j-2];
	}
	else if(j==2){
		if(a[i][j-1]>a[i][j+1])return a[i][j-1];
		else return a[i][j+1];
	}
	else {
		if(a[i][j+1]>a[i][j+2])return a[i][j+1];
		else return a[i][j+2];
	}
}
int cop(int j,int o){
    int e[100005]={};
    for(int i=1;i<=n;i++)e[i]=a[i][j];
    sort(e+1,e+n+1);
    for(int i=1;i<=n;i++){
    	if(a[i][j]==e[o]&&d[i][j]!=1){
    		d[i][j]=1;
		    return i;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=3;j++)d[i][j]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=3;j++)cin>>a[i][j];
		for(int i=1;i<=n;i++){
		    s[k]+=com(k,i);
	    }
	    for(int i=1;i<=3;i++){
	    	int o=1; 
    	    while(b[k][i]>n/2){
    	    	s[k]-=a[cop(i,o)][i];
	            s[k]+=mxn(cop(i,o),i);
	            b[k][i]--;
	            o++;
			}
		}
	}
	for(int i=1;i<=t;i++)cout<<s[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
