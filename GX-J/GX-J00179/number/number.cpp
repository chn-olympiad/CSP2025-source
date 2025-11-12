#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int z=a.size()-1,b[100005];
    for(int i=0;i<=z;i++){
        b[i]=-1;
        if(a[i]>=48&&a[i]<=57){
            int z=a[i];
            b[i]=z-48;
        }
    }
    for(int i=0;i<=z;i++){
        for(int j=i+1;j<=z;j++)if(b[i]<b[j])swap(b[i],b[j]);
    }
    for(int i=0;i<=z;i++)if(b[i]!=-1)cout<<b[i];
    return 0;
}

