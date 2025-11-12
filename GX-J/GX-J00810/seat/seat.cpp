#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
ios::sync_with_stdio(false);
cin>>n>>m;
int a[n*m+5];
for(int i=0;i<n*m;i++){
    cin>>a[i];
}
int al=a[0];
for(int i=0;i<n*m;i++){
    for(int j=0;j<n*m;j++){
        if(a[i]>a[j]){
            swap(a[i],a[j]);
        }


}

}











int r=0;
for(int i=0;i<n*m;i++){
    if(a[i]==al){
        r=i;
    }
}
r++;




if((r-1)/n%2==0)//jishu{
{
    cout<<(r-1)/(n)+1<<" "<<(r-1)%n+1;return 0;
}
cout<<(r-1)/(n)+1<<" "<<n-(r-1)%n;return 0;









return 0;
}

