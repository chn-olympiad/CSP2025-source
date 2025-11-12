
#includes<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,a,b,c=1;
cin>>n>>m>>a;
for(int i=1;i<=n*m;i++){
    cin>>b;
    if(b>a)c++;
}
if(c%2n>n)cout<<2n-c+1;
else cout<<c;
cout<<(c-c%n)/n+1;
fclose(stdin);
fclose(stdout);
    return 0;
}





