
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1000005];
int stick[1000005];
int ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
        scanf("%d",&stick[i]);
	}
	sort(stick+1,stick+1+n);
	for(int i=1;i<=n;i++){
        arr[i]=arr[i-1]+stick[i];
	}
	for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            for(int k=1;k<=j;k++){
                int num=arr[j]-arr[k-1]+stick[i];
                if(num>stick[i]*2){
                    ans++;
                }
            }
        }
	}
	cout<<ans;
	return 0;
}
