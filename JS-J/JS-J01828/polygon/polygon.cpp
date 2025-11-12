#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int f(int a){
	int m=1;
	for(int i=1;i<=a;i++){m*=i;m%=998244353;}return m;}
int c(int m,int n){
	return (f(m)/f(n)/f(m-n));}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a,b[5005],cnt=0;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];};
	sort(b,b+a);
	if(a==3){
		if(b[1]+b[0]>b[2]){cout<<1;return 0;}}
	if(b[a-1]==1){
		for(int i=3;i<=a;i++){
			cnt+=c(a,i);cnt%=998244353;}}
	cout<<cnt;
    return 0;
}
