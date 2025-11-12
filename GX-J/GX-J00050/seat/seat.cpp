#include<bits/stdc++.h>
using namespace std;
int n,numl,numr;
int xiao,xiaonum=1;
int a[101];
bool cmp(int a,int b){
    return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>numr>>numl;
    n=numl*numr;
    cin>>xiao;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    sort(a+1,a+n,cmp);
    for(int i=1;i<=n-1;i++){
        if(a[i]>xiao){
            xiaonum++;
        }else{
            break;
        }
    }
    int m=xiaonum/numr;
    int xy=m+1;
    if(xy%2==0){
        cout<<numr-(xiaonum%(numr*m))<<" ";
        cout<<xy;
    }else{
        cout<<xiaonum%(numr*m)<<" ";
        cout<<xy;
    }
    fclose(stdin);
	fclose(stdout);
    return 0;
}

