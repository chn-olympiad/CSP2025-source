#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s[105],a[12][12],b=1;
	cin>>n>>m;
	int q=n*m;
	for(int i=0;i<q;i++){cin>>s[i];}//s+a,s+b->s[a],s[b-1]
	int c=s[0];
	sort(s,s+q);
	for(int i=0;i<m;i++){
		if(b){
			for(int j=0;j<n;j++){
				a[j][i]=s[q-i*n-j-1];}}
		else {
			for(int j=n-1;j>=0;j--){
				a[j][i]=s[q-(i+1)*n+j];}}
		b=!b;}
		
	for(int i=0;i<n;i++){for(int j=0;j<m;j++){if(a[i][j]==c)cout<<j+1<<' '<<i+1;}}
    return 0;
}
	
