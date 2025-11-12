#include <bits/stdc++.h>
using namespace std;
struct student{
    int mark;
    int number;
    int x,y;
}stud[400];
bool cmp(student a,student b){
    if(a.mark>b.mark){
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;//n small change   m big change
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>stud[i].mark;
    }
    int ans=stud[0].mark;
    sort(stud,stud+n*m,cmp);
    //for(int i=0;i<n*m;i++)
    for(int i=0;i<n*m;i++){
        stud[i].number=i;
    }
    int cou=0;
    for(int x1=1;x1<=m;){
        for(int y1=1;y1<=m*n;y1++){
            if(y1%n==0){
                stud[cou].y=n;
                stud[cou].x=x1;
            }
            else{
                stud[cou].y=y1%n;
                stud[cou].x=x1;
            }
            if(y1%n==0){
                x1++;
                //y1%=n;
            }
            cou++;
        }
    }
    for(int i=0;i<400;i++){
        if(stud[i].mark==ans){
            cout<<stud[i].x<<' '<<stud[i].y<<endl;
        }
    }
    //cout<<"\n\n\n\n";
    //for(int i=0;i<400;i++){
       // cout<<stud[i].mark<<' '<<stud[i].number<<' '<<stud[i].x<<' '<<stud[i].y<<endl;
   // }
    return 0;
}
