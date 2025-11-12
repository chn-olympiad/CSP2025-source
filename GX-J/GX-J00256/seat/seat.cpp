#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int k=0,l=0;
int main(){
//freopen("seat","r",stdin);
//freopen("seat","w",stdout);
cin >> n>>m;
for(int i=0;i<n*m;i++){
    cin >> a[i];
    if(a[1]<a[i]){
        a[i]=a[1];
        a[1]++;
        k++;
    }
}
l=m*n-k;
cout << l;
//fclose(stdin);
//fclose(stdout);
return 0;
}
