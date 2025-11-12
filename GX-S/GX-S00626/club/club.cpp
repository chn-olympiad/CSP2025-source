#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct student{
    int one;
    int two;
    int three;
    student(int o1,int t1,int th1){
        one=o1;
        two=t1;
        three=th1;
    }
};
bool pd1(student a1,student a2){
    return a1.one-max(a1.two,a1.three)<a2.one-max(a2.two,a2.three);
}
bool pd2(student a1,student a2){
    return a1.two-max(a1.one,a1.three)<a2.two-max(a2.one,a2.three);
}
bool pd3(student a1,student a2){
    return a1.three-max(a1.two,a1.one)<a2.three-max(a2.one,a2.two);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,number,first,second,third;
    scanf("%d",&t);
    vector<student>club,a,b,c;
    for(int i=0;i<t;i++){
        scanf("%d",&number);
        for(int o=0;o<number;o++){
            scanf("%d%d%d",&first,&second,&third);
            club.push_back(student(first,second,third));
            if(club[club.size()-1].one>max(club[club.size()-1].two,club[club.size()-1].three)){
                a.push_back(student(club[club.size()-1].one,club[club.size()-1].two,club[club.size()-1].three));
            }
            else if(club[club.size()-1].two>club[club.size()-1].three){
                b.push_back(student(club[club.size()-1].one,club[club.size()-1].two,club[club.size()-1].three));
            }
            else{
                c.push_back(student(club[club.size()-1].one,club[club.size()-1].two,club[club.size()-1].three));
            }
        }
        while(a.size()>number/2||b.size()>number/2||c.size()>number/2){
            sort(a.begin(),a.end(),pd1);
            sort(b.begin(),b.end(),pd2);
            sort(c.begin(),c.end(),pd3);
            if(a.size()>number/2){
                while(a.size()>number/2){
                    if(a[0].two>a[0].three){
                        b.push_back(student(0,a[0].two,a[0].three));
                        a.erase(a.begin());
                    }
                    else{
                        c.push_back(student(0,a[0].two,a[0].three));
                        a.erase(a.begin());
                    }
                }
            }
            if(b.size()>number/2){
                while(b.size()>number/2){
                    if(a[0].one>a[0].three){
                        a.push_back(student(b[0].one,0,b[0].three));
                        b.erase(b.begin());
                    }
                    else{
                        c.push_back(student(b[0].one,0,b[0].three));
                        b.erase(b.begin());
                    }
                }
            }
            if(c.size()>number/2){
                while(c.size()>number/2){
                    if(c[0].one>c[0].two){
                        a.push_back(student(c[0].one,c[0].two,0));
                        c.erase(c.begin());
                    }
                    else{
                        b.push_back(student(c[0].one,c[0].two,0));
                        c.erase(c.begin());
                    }
                }
            }
        }
        ll shu=0;
        for(int o=0;o<a.size();o++){
            shu+=a[o].one;
        }
        for(int o=0;o<b.size();o++){
            shu+=b[o].two;
        }
        for(int o=0;o<c.size();o++){
            shu+=c[o].three;
        }
        cout<<shu<<endl;
        club.clear();
        a.clear(),b.clear(),c.clear();
    }
    return 0;
}
