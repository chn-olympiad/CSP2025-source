#include<bits/stdc++.h>
using namespace std;
long long int t;
long long int aaa(){
    long long int n,i,j,s=0,x=0,y=0,z=0,c=0,e=0,f=0,p=0;
    cin>>n;
    long long int a[n][3],b[n][3],d[n];
    for(i=0;i<n;i++)
    for(j=0;j<3;j++){
    d[i]=20001;
	b[i][j]=-1;
    cin>>a[i][j];}
    for(i=0;i<n;i++){
    	if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
		x++;
    	b[i][0]=a[i][0];
		s+=b[i][0];}
    	else
    	
    	if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
		y++;
    	b[i][1]=a[i][1];
		s+=b[i][1];}
    	else
    	
    	if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]){
		z++;
    	b[i][2]=a[i][2];
		s+=b[i][2];}
    	}
    	if(x>n/2){
		e=1;f=2;
    	c=0;p=x;}
    	else
    	if(y>n/2){
		e=0;f=2;
    	c=1;p=y;}
    	else
    	if(z>n/2){
		e=0;f=1;
    	c=2;p=z;}
    	else{
    		return s;
		}
		for(i=0;i<n;i++){
			if(b[i][c]>-1){
				d[i]=b[i][c]-max(a[i][e],a[i][f]);
			}
		}sort(d,d+n);
		for(i=0;i<p-n/2;i++)
		s-=d[i];
		return s;
	}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	long long int i,a[t];
	for(i=0;i<t;i++)
	a[i]=aaa();
	for(i=0;i<t;i++)
	cout<<a[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
