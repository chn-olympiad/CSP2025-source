#include<bits/stdc++.h>
using namespace std;
struct student{
    int number,grade;
};
bool rule(const student&a,const student&b){
    return a.grade>b.grade;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x=1,y=1;
    bool b=0;
    cin>>n>>m;
    student s[n*m+1];
    for(int i=0;i<n*m;i++){
        cin>>s[i].grade;
        s[i].number=i;
    }
    sort(s,s+n*m,rule);
    for(int i=0;i<n*m;i++){
        if(x%2==1){
            if(y>n){
                y=n;
                x++;
                b=1;
            }

            if(s[i].number==0){
                cout<<x<<" "<<y;
                break;
            }
            if(b==0){
                y++;
            }
            else y--;
            b=0;
        }
        else{
            if(y<1){
                y=1;
                x++;
                b=1;
            }
            if(s[i].number==0){
                cout<<x<<" "<<y;
                break;
            }
            if(b==0){
                y--;
            }
            else y++;
            b=0;
        }

    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
