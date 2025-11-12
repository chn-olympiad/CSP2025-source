#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;

int a[m*n];
for(int i=0;i<m*n;i++){
cin>>a[i];
}
for(int i=1;i<m*n;i++){
if(a[i]>a[0]){
cnt++;
}
}
cnt++;
if(m*n==1)
cout<<1<<' '<<1;
else if(cnt<=n)
cout<<1<<' '<<cnt;
else {
if(cnt%n==0){
	int l=cnt/n;
if(l%2==0)
cout<<cnt/n<<' '<<1;
else cout<<cnt/n<<' '<<n;
}

else {
int lie=cnt/n+1;
int hang;
if(lie%2==0){
hang=n-cnt%n+1;
cout<<lie<<' '<<hang;
}
else{
hang=cnt%n;
cout<<lie<<' '<<hang;
}
}
}


fclose(stdin);
fclose(stdout);
return 0;
}
