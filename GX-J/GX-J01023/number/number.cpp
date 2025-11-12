#include <bits/stdc++.h>
using namespace std;
string aaa;
int a[101010],sum=0;
bool cmp(int x,int y){
    return x>y;

}
int main(){
    freopen("number.in","r","stdin");
    freopen("number.out","w","stdout");
	cin>>aaa;
    int n=aaa.length();

    for(int i=0;i<n;i++){
        if(a[i]=='0')a[i]=0;sum++;
        if(a[i]=='1')a[i]=1;sum++;
        if(a[i]=='2')a[i]=2;sum++;
        if(a[i]=='3')a[i]=3;sum++;
        if(a[i]=='4')a[i]=4;sum++;
        if(a[i]=='5')a[i]=5;sum++;
        if(a[i]=='6')a[i]=6;sum++;
        if(a[i]=='7')a[i]=7;sum++;
        if(a[i]=='8')a[i]=8;sum++;
        if(a[i]=='9')a[i]=9;sum++;
    }
    sort(a,a+sum-1,cmp);
    for(int i=0;i<sum;i++){
        cout<<a[i];
    }
    return 0;
}
