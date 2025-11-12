#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],p,cnt=1;
bool cmp(int& x,int& y){
	return x>y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
}
p=a[1];
sort(a+1,a+n*m+1,cmp);
for(int i=1;i<=m;i++){
	if(i%2==1){
		for(int j=1;j<=n;j++){
		if(p==a[cnt]){
			cout<<i<<" "<<j;
			return 0;
		}
		cnt++;
		
		}
	}
	else{
		for(int j=n;j>=1;j--){
		if(p==a[cnt]){
			cout<<i<<" "<<j;
			return 0;
		}
		cnt++;
		
		}
	}
	
}

fclose(stdin);
fclose(stdout); 
return 0;
}
