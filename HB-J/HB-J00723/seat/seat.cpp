#include<bits/stdc++.h>
using namespace std;
struct Node{
    int grades;
    int id;
}student[1000];
bool cmp(Node a,Node b){
    return a.grades>b.grades;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=n*m;i++){
        cin>>student[i].grades;
        student[i].id=i;
    }
    sort(student+1,student+1+n*m,cmp);
    int r=1,c=1,ans=1;
    bool op=0;
    while(1){
        if(op==0){
            if(c<n){
                c++;
                ans++;
            }
            else{
                r++;
                ans++;
                op=1;
            }
        }
        else{
            if(c>1){
                c--;
                ans++;
            }
            else{
                r++;
                ans++;
                op=0;
            }
        }
        if(student[ans].id==1){
            cout<<r<<' '<<c;
            return 0;
        }
    }
    return 0;
}
//HB-J00723 shizouyu 04-03 2025.11.01  ⨌
