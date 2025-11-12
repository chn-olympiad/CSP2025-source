#include<bits/stdc++.h>
using namespace std;
struct node{
    int maxx;
    int maxxid;
    int mid;
    int midid;
    int A;
    int B;
    int C;
};
node a[100005];
int n;
bool cmp(node a1,node b){
    if(a1.maxxid!=b.maxxid)return a1.maxxid<b.maxxid;
    else return a1.maxx>b.maxx;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
while(t--){
    n=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int A,B,C;
        cin>>A>>B>>C;
        a[i].A=A;
        a[i].B=B;
        a[i].C=C;
        if(A==max(A,max(B,C))){
            a[i].maxx=A;
            a[i].maxxid=1;
            if(B==max(C,B)){
            a[i].mid=B;
            a[i].midid=2;
            }else{
            a[i].mid=C;
            a[i].midid=3;
            }
        }if(B==max(A,max(B,C))){
            a[i].maxx=B;
            a[i].maxxid=2;
            if(B==max(C,A)){
            a[i].mid=A;
            a[i].midid=1;
            }else{
            a[i].mid=C;
            a[i].midid=3;
            }
        }if(C==max(A,max(B,C))){
            a[i].maxx=C;
            a[i].maxxid=3;
            if(B==max(A,B)){
            a[i].mid=B;
            a[i].midid=2;
            }else{
            a[i].mid=A;
            a[i].midid=1;
            }
        }
    }
    sort(a+1,a+1+n,cmp);
    int A=0,B=0,C=0,da=0;
    for(int i=1;i<=n;i++){
        if(A!=n/2&&a[i].maxxid==1){
            da+=a[i].maxx;
            A++;
        }else{
            if(a[i].maxxid==2&&B!=n/2){
                da+=a[i].maxx;
                B++;
            }else if(a[i].maxxid==3&&C!=n/2){
                da+=a[i].maxx;
                C++;
            }
            else if(A==n/2&&a[i].midid==2){
                B++;
                da+=a[i].mid;
            }else{
                C++;
                da+=a[i].mid;
            }
        }
    }
    cout<<da<<endl;
}
return 0;
}
