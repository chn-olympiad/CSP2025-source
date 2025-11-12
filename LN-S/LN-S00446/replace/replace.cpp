#include<bits/stdc++.h>
using namespace std;
int n,m,arr[501]={},fl=1,sumc0=0,sum=1;
string str;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    cin>>str;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==0)sumc0++;
    }for(int i=0;i<str.length();i++){
        if(str[i]==0){
            fl=0;
        }
    }if(fl){
            if(sumc0==0){
                for(int i=2;i<=n;i++){
                    sum*=i;
                }cout<<sum;
            }else{
                if(n==m)cout<<0;
            }
        }

    }fclose(stdin);
    fclose(stdout);
    return 0;
}

                           l
                           L    P
           0000          0000000000
ooooooooooo0000ooooooooooo00000000oooooooooooooooooooooooooooooooooooooooooooooooo
^^^^^^^^^^^0000^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
vvvvvvvvvvv0000vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
ooooooooooo0000ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
           0000



           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-T
            __[_]
           (
           O] <^>
            L[   ]-G
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-C
            __[_]
           (
           O] <^>
            L[   ]-G
            __[_]
           (
           O] <^>
            L[   ]-T
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (
           O] <^>
            L[   ]-A
            __[_]
           (

            H        H        H        H        H
            |        |        |        |        |
        NH3-C-CO-NH2-C-CO-NH2-C-CO-NH2-C-CO-NH2-C-COOH
            |        |        |        |        |
            R        R        R        R        R




