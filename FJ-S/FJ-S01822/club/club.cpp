#include<bits/stdc++.h>

using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int T;
cin>>T;
for(int lorr=0;lorr<T;lorr++){
int n;
cin>>n;
int a[n][3];
for(int i=0;i<n;i++){
for(int j=0;j<3;j++){
	cin>>a[i][j];
}}
long long ja[n]={0},jb[n]={0};
long long m=0;
for(int i=0;i<n;i++){
if(a[i][0]<=a[i][1])
	ja[i]=a[i][1]-a[i][0];
if(a[i][0]>a[i][1])
	jb[i]=a[i][0]-a[i][1];
m+=min(a[i][1],a[i][0]);
}
sort(ja,ja+n);
sort(jb,jb+n);
for(int i=n-1;i>=n/2;i--){
	m+=ja[i]+jb[i];
}
cout<<m<<endl;
}
fclose(stdin);
fclose(stdout);
return 0;
}
