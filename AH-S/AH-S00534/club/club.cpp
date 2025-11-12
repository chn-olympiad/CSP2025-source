#include <bits/stdc++.h>
using namespace std;
int t,n,a[100003],b[100003],c[100003];
long long sum=0;
int my(int x){
    for(int i=1;i<=x;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    sort(a+1,a+x+1);
    for(int i=x;i>x/2;i--){
        sum=sum+a[i];
    }
    cout<<sum<<endl;
    sum=0;
    return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        my(n);
    }
	return 0;
}
