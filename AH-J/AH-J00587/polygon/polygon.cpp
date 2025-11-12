#include<bits/stdc++.h>
using namespace std;
int n,a[1005],m,sum[100005],k,cnt,t,f[5005][5005];//f[i选取i个木棍能拼成的多边形数量
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i];
}if(n<3){
	cout<<0;
	exit(0);
}
if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[3]+a[1]>a[2]){
	cout<<1;
}else{
	cout<<0;
}
fclose(stdin);
fclose(stdout);
	return 0;
}
