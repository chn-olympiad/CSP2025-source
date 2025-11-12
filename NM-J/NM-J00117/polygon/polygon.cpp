#include<bits/stdc++.h>
using namespace std;
int n;
int out , sum;
int a[10000];
int jx;
int panduan(int x){
    int jilu=0;
    for(int i=x;i<=n;i++){
    	if(jilu<a[i]) jilu=a[i];
            out+=a[i];
        for(int j=i+1;j<=n;j++){
            if(jilu<a[j]) jilu=a[j];
            out=out+a[j];
            if(jilu*2<out){
                sum++;
            }
            if(jilu*2>out){
            	panduan(j+1);
			}
        }
    }
    jx=sum;
    sum=0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    panduan(1);
	cout<<jx<<endl;
}
