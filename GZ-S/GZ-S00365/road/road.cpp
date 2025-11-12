//GZ-S00365 贵阳市第一中学 罗李镜 
#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][5]={},s[10]={},b[10][5]={};
int com(int k,int i){
	int p=1,v=a[i][1];
	for(int j=1;j<3;j++)if(a[i][j]<a[i][j+1]){
		v=a[i][j+1];
		p=j+1;
	}
	b[k][p]++;
	return v;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
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
	return 0;
	fclose(stdin);
	fclose(stdout);
}
