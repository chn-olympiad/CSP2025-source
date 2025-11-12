#include<bits/stdc++.h>
using namespace std;
int n,m,w;
int a[105]={0};
int cmp(int a,int b){
      return a>b;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
int b=n*m;
for(int i=1;i<=b;i++){
    cin>>a[i];
}
int w=a[1];
sort(a+1,a+b+1,cmp);
for(int i=1;i<=n;i++){
    cout<<a[i]<<" "<<endl;
}
for(int i=1;i<=m;i++){
    cout<<a[i]<<" "<<endl;
}
for(int i=1;i<=b;i++){
    cout<<a[i]<<" ";
}
cout<<endl<<w;
fclose(stdin);
fclose(stdout);
    return 0;
}

