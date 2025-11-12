#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	getline(a,cin);
	int sum,x=0,b[a.size()];
	for(int i=0;i<a.size();i++){
	if(a[i]>=0&&a[i]<=9){
        b[x]=a[i];
        x++;
	}
    }
    for(int j=0;j<x;j++){
        for(int k=0,k<x;k++){
            if(b[k]<b[k+1]){
                swap(b[k],b[k+1]);
            }
        }
    }
    sum=b[0];
    for(int i=0;i<x;i++){
        sum*=10;
        sum+=b[i+1];
    }
    cout<<sum;
    return 0;
}