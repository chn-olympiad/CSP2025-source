#include<bits/stdc++.h>
using namespace std;

long long n;
long long num[5005];

bool is_ok(int a,int b,int c){
    if((a+b+c)>max(max(a,b),c)){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;

    for(int i =1;i<=n;i++){
        cin>>num[i];
    }
    if(is_ok(num[1],num[2],num[3])){
        cout<<1;
    }
    else{
        cout<<0;
    }

	return 0;
}
