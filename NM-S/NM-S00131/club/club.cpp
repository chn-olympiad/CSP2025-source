#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c;
int s,j,k;
int o,v,l;
int z;
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<=t;i++){
        cin>>n;
        for(int m=0;m<=n;m++){

            cin>>s>>j>>k;
            if(s>j>k){
                a++;
                o=o+s;}
            else if(j>k>s){
                b++;
                l=l+m;}
            else if(k>s>j){
                c++;
                v=v+k;}
				z=o+v+l;}
                if(a>n/2||b>n/2||c>n/2){
                for(int p=0;p<=n;p++){

            cin>>s>>j>>k;
            if(s>j>k){
                b++;
                o=o+s;}
            else if(j>s>k){
                c++;
                l=l+k;}
            else if(k>s>j){
                a++;
                v=v+k;}
				z=o+v+l;}
                }if(a>n/2||b>n/2||c>n/2){
                for(int q=0;q<=n;q++){
            if(s>j>k){
                c++;
                o=o+s;}
            else if(j>k>s){
                a++;
                l=l+m;}
            else if(k>s>j){
                b++;
                v=v+k;}
                z=o+v+l;}else{
                    z=o+v+l;
                }
        }
        cout<<z;
    }

    return 0;
}
