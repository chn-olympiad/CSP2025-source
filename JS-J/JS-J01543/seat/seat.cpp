#include<bits/stdc++.h>
using namespace std;
int a[2000],n,m,p,x=1,y=1,add=1;
bool cmp(int a,int b){
    return a>b;
}
string s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){

        cin>>a[i];
        if(i==1){
            p=a[i];
        }
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m*n;i++){
            //cout<<a[i]<<" "<<x<<" "<<y<<" "<<endl;
        if(a[i]==p){
            cout<<y<<" "<<x<<endl;
            return 0;
        }
        if(x==n&&add==1){
            y++;
            add=-1;
        }else if(x==1&&add==-1){
            y++;
            add=1;
        }else x+=add;
    }
    //cout<<"finish "<<p<<endl;
	return 0;
}







/*
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
2 2
99 100 97 98


100 95 94
 99 96
 98 97
 5 5
87 6 43 5 47 56 44 45 63 4 73 86 48  100 67 98 95 8 99  31  1 76 90  36  69
*/
