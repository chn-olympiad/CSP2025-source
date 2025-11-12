#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using numespace std:
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    int n,m,num=0;
    cin>>n>>m;
    int b[1000][1000]={0};
	int a[10000]{0};
	for(int i=0;i<n*m;i++){
        cin>>a[i];
        num=a[i];
	}
	for(int i=0;i<n*m;i++){
        sore(a[i],a[i+1]);
	}
	int sum=0;
	for(int i=0;i<m;i++){
        if(i%2!=1){
            for(int k=m;k>0;k--)
                b[k][i]=a[sum];
                if(b[k][i]==num){
                    cout<<k+1<<i+1;
                    break;
                }else{
                    break;
                }
        }else{
            for(int j=0;j<n;j++){
                b[k][i]=a[sum];
                if(b[j][i]==num){
                    cout<<j+1<<i+1;
                    break;
                }else{
                    break;
                }
            }
        }
        sum++;
	}
    return 0;
}
