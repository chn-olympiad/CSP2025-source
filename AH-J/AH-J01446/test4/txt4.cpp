#include<bits/stdc++.h>
using namespace std;
int main(){
int a[10000];
int n;
cin >> n;
for(int i=0;i<n;i++){
    cin >> a[i];
}
sort(a,a+n);
int sum=0;
for(int i=3;i<n+1;i++){
    int b=0;
    if(a[b]+a[i-2]+a[i-1]>a[i+1]){
        sum += 1;
    }
    if (i=n){
        b++;
    }
}
cout << sum;
    return 0;
}
