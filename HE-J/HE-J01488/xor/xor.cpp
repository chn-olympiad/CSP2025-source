#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int a[999999],k,j,num,d,e=0;
cin>>j>>k;
for(int i=0;i<j;i++){
    cin>>num;
    if(num=k){
        d+=1;
        a[i]=0;
    }
    else a[i]=num;
}
for(int i=0;i<j;i++)
{
    for(int j1=i;j1>=0;j--){
        for(int p=0;p<i;p--)
            e+=a[j1+p];
        if(e%2==k) {
		d+=1;
		}
        e=0;
    }

}
cout<<d;
}












