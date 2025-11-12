#include <bits/stdc++.h>
using namespace std;
struct ABC{
    int m1,m2,m3;
};
ABC a[200009];
int zdyw(int j){
    if(a[j].m1>=a[j].m2&&a[j].m1>=a[j].m3){
        return 0;

    }
    else if(a[j].m2>=a[j].m1&&a[j].m2>=a[j].m3){
        return 1;
    }
    else{
        return 2;
    }
}
int zdew(int j){
    if((a[j].m1<=a[j].m2&&a[j].m1>=a[j].m3)||(a[j].m1<=a[j].m3&&a[j].m1>=a[j].m2)){
        return 0;
    }
    else if((a[j].m2<=a[j].m1&&a[j].m2>=a[j].m3)||(a[j].m2<=a[j].m3&&a[j].m2>=a[j].m1)){
        return 1;
    }
    else{
        return 2;
    }
}
int zdsw(int j){
    if(a[j].m3<=a[j].m2&&a[j].m3<=a[j].m1){
        return 2;
    }
    else if(a[j].m2<=a[j].m1&&a[j].m2<=a[j].m3){
        return 1;
    }
    else{
        return 0;
    }
}
bool cmp1(ABC f1,ABC f2){
    int a[3]={f1.m1,f1.m2,f1.m3};
    int a2[3]={f2.m1,f2.m2,f2.m3};
    sort(a,a+3);
    sort(a2,a2+3);
    return a[2]-a[1]>a2[2]-a2[1];
    //f(a[0]==a2[0]){
    //    if(a[1]==a2[1]){
    //        return a[2]>a2[2];
    //    }
    //    else{
    //        return a[1]>a2[1];
    //    }
    //}
    //else{
    //    return a[0]>a2[0];
    //}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,j[3]={},zjsq=0;
    cin>>t;
    int rs;
    for(int i=0;i<t;i++){
        cin>>rs;
        zjsq=0;
        j[0]=0;
        j[1]=0;
        j[2]=0;

        for(int j3=0;j3<rs;j3++){
            cin>>a[j3].m1>>a[j3].m2>>a[j3].m3;
        }
        sort(a,a+rs,cmp1);
        for(int j2=0;j2<rs;j2++){
            int jw=zdyw(j2);
            if(j[jw]<rs/2){
                j[jw]++;
                if(jw==0){
                    zjsq+=a[j2].m1;
                }
                else if(jw==1){
                    zjsq+=a[j2].m2;
                }
                else if(jw==2){
                    zjsq+=a[j2].m3;
                }
            }
            else{
                jw=zdew(j2);
                if(j[jw]<rs/2){
                    j[jw]++;
                    if(jw==0){
                        zjsq+=a[j2].m1;
                    }
                    else if(jw==1){
                        zjsq+=a[j2].m2;
                    }
                    else if(jw==2){
                        zjsq+=a[j2].m3;
                    }

                }
                else{
                    jw=zdsw(j2);
                    j[jw]++;
                    if(jw==0){
                        zjsq+=a[j2].m1;
                    }
                    else if(jw==1){
                        zjsq+=a[j2].m2;
                    }
                    else if(jw==2){
                        zjsq+=a[j2].m3;
                    }

                }
            }
        }
        cout<<zjsq<<endl;
    }

    return 0;
}
/*3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
