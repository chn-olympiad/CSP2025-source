#include<bits/stdc++.h>
using namespace std;
struct club{
    int ok1;
    int ok2;
    int ok3;
};
struct ub{
    int maxx;
    int cl;

};
int ma(int a,int b,int c){
    int x=0;
    x=max(a,b);
    return max(x,c);
}
bool cmp(ub a,ub b){
    return a.maxx<b.maxx;
}
bool cmp1(club a,club b){
    return a.ok1>b.ok1;
}
bool cmp2(club a,club b){
    return a.ok2>b.ok2;
}
bool cmp3(club a,club b){
    return a.ok3>b.ok3;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int qwe=0;qwe<t;qwe++){
        int n=0,c1=0,c2=0,c3=0,m=0;
        vector<ub> cm(4);
        for(int i=0;i<4;i++){
            cm[i].maxx=0;
            cm[i].cl=0;
        }
        cin>>n;
        vector<club> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].ok1>>a[i].ok2>>a[i].ok3;
        }
        for(int i=0;i<n;i++){
            cm[1].maxx=a[i].ok1+cm[1].maxx;
            cm[1].cl=1;
            cm[2].maxx=a[i].ok2+cm[2].maxx;
            cm[2].cl=2;
            cm[3].maxx=a[i].ok3+cm[3].maxx;
            cm[3].cl=3;
        }
        //fuck!!!c1
        sort(cm.begin(),cm.end(),cmp);
        if(cm[1].cl==1){
            sort(a.begin(),a.end(),cmp1);
            for(int i=0;i<n/2;i++){
                c1=a[i].ok1+c1;
                a[i].ok1=0;
                a[i].ok2=0;
                a[i].ok3=0;

            }
        }
        else if(cm[1].cl==2){
            sort(a.begin(),a.end(),cmp2);
            for(int i=0;i<n/2;i++){
                c2=a[i].ok2+c1;
                a[i].ok1=0;
                a[i].ok2=0;
                a[i].ok3=0;
            }
        }
        else{
            sort(a.begin(),a.end(),cmp3);
            for(int i=0;i<n/2;i++){
                c3=a[i].ok3+c1;
                a[i].ok1=0;
                a[i].ok2=0;
                a[i].ok3=0;
            }
        }
        //c2
        if(cm[2].cl==1){
            sort(a.begin(),a.end(),cmp1);
            for(int i=0;i<n/2;i++){
                if(ma(a[i].ok1,a[i].ok2,a[i].ok3)==a[i].ok1){
                    c1=c1+a[i].ok1;
                    a[i].ok1=0;
                    a[i].ok2=0;
                    a[i].ok3=0;
                }
            }
        }
        else if(cm[2].cl==2){
            sort(a.begin(),a.end(),cmp2);
            for(int i=0;i<n/2;i++){
                if(ma(a[i].ok1,a[i].ok2,a[i].ok3)==a[i].ok2){
                    c2=c2+a[i].ok1;
                    a[i].ok1=0;
                    a[i].ok2=0;
                    a[i].ok3=0;
                }
            }
        }
        else{
            sort(a.begin(),a.end(),cmp3);
            for(int i=0;i<n/2;i++){
                if(ma(a[i].ok1,a[i].ok2,a[i].ok3)==a[i].ok3){
                    c3=c3+a[i].ok1;
                    a[i].ok1=0;
                    a[i].ok2=0;
                    a[i].ok3=0;
                }
            }
        }

        //c3
        if(cm[3].cl==1){
            for(int i=0;i<n;i++){
                c3=c3+a[i].ok1;
            }
        }

        else if(cm[3].cl==2){
            for(int i=0;i<n;i++){
                c3=c3+a[i].ok2;
            }
        }
        else{
            for(int i=0;i<n;i++){
                c3=c3+a[i].ok3;
            }
        }
        cout<<c1+c2+c3<<endl;
    }
    return 0;
}
//what fack?!
