#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;
cin>>n;
int a[n];
int ans=0;
if(n<3){cout<<0;return 0;}
if(n==3){if(a[0]+a[1]+a[2]>2*a[2]){cout<<1;return 0;}else{cout<<0;return 0;}}
if(n==4){
	if(a[0]+a[1]+a[2]+a[3]>2*a[3])ans++;
	if(a[0]+a[1]+a[2]>2*a[2])ans++;
	if(a[0]+a[1]+a[3]>2*a[3])ans++;
	if(a[0]+a[2]+a[3]>2*a[3])ans++;
	if(a[1]+a[2]+a[3]>2*a[3])ans++;
}
else if(n==5){
	if(a[0]+a[1]+a[2]+a[3]+a[4]>2*a[4])ans++;
	if(a[0]+a[1]+a[2]+a[3]>2*a[3])ans++;
	if(a[0]+a[1]+a[2]>2*a[2])ans++;
	if(a[0]+a[1]+a[3]>2*a[3])ans++;
	if(a[0]+a[2]+a[3]>2*a[3])ans++;
	if(a[1]+a[2]+a[3]>2*a[3])ans++;
	if(a[0]+a[1]+a[2]+a[4]>2*a[4])ans++;
	if(a[0]+a[1]+a[2]>2*a[2])ans++;
	if(a[0]+a[1]+a[3]>2*a[3])ans++;
	if(a[0]+a[2]+a[3]>2*a[3])ans++;
	if(a[1]+a[2]+a[3]>2*a[3])ans++;
}
cout<<ans;
return 0;
}
