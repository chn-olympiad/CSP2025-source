#include<bits/stdc++.h>
using namespace std;
int t,n,ans[10],yj[10],ANS,minn;
struct Stu1{
    int a1,a2,a3;
    int x,flag,x2,flag2,x3,flag3;
}stu1[100010];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int j=1;j<=t;j++){
        memset(ans,0,sizeof(ans));
        memset(yj,0,sizeof(yj));
        cin>>n;
        for(int i=1;i<=n;i++){
            minn=0;
            cin>>stu1[i].a1>>stu1[i].a2>>stu1[i].a3;
            if(stu1[i].a1>=stu1[i].a2&&stu1[i].a2>=stu1[i].a3){
                stu1[i].x=stu1[i].a1;
                stu1[i].flag=1;
                stu1[i].x2=stu1[i].a2;
                stu1[i].flag2=2;
                stu1[i].x3=stu1[i].a3;
                stu1[i].flag3=3;
            }else if(stu1[i].a1>=stu1[i].a3&&stu1[i].a3>=stu1[i].a2){
                stu1[i].x=stu1[i].a1;
                stu1[i].flag=1;
                stu1[i].x2=stu1[i].a3;
                stu1[i].flag2=3;
                stu1[i].x3=stu1[i].a2;
                stu1[i].flag3=2;
            }else if(stu1[i].a2>=stu1[i].a1&&stu1[i].a1>=stu1[i].a3){
                stu1[i].x=stu1[i].a2;
                stu1[i].flag=2;
                stu1[i].x2=stu1[i].a1;
                stu1[i].flag2=1;
                stu1[i].x3=stu1[i].a3;
                stu1[i].flag3=3;
            }else if(stu1[i].a2>=stu1[i].a3&&stu1[i].a3>=stu1[i].a1){
                stu1[i].x=stu1[i].a2;
                stu1[i].flag=2;
                stu1[i].x2=stu1[i].a3;
                stu1[i].flag2=3;
                stu1[i].x3=stu1[i].a1;
                stu1[i].flag3=1;
            }else if(stu1[i].a3>=stu1[i].a1&&stu1[i].a1>=stu1[i].a2){
                stu1[i].x=stu1[i].a3;
                stu1[i].flag=3;
                stu1[i].x2=stu1[i].a1;
                stu1[i].flag2=1;
                stu1[i].x3=stu1[i].a2;
                stu1[i].flag3=2;
            }else if(stu1[i].a3>=stu1[i].a2&&stu1[i].a2>=stu1[i].a1){
                stu1[i].x=stu1[i].a3;
                stu1[i].flag=3;
                stu1[i].x2=stu1[i].a2;
                stu1[i].flag2=2;
                stu1[i].x3=stu1[i].a1;
                stu1[i].flag3=1;
            }
        }
        //for(int i=1;i<=n;i++){
            //cout<<stu1[i].x<<' '<<stu1[i].flag<<' '<<stu1[i].x2<<' '<<stu1[i].flag2<<' '<<stu1[i].x3<<' '<<stu1[i].flag3<<endl;
        //}
        //for(int i=1;i<=n;i++){
            //cout<<stu1[i].a1<<' '<<stu1[i].a2<<' '<<stu1[i].a3<<endl;
        //}
        if(stu1[1].flag!=stu1[2].flag){
            cout<<stu1[1].x+stu1[2].x<<endl;
        }else{
            if(stu1[1].x>stu1[2].x){
                cout<<stu1[1].x+stu1[2].x2<<endl;
            }else if(stu1[1].x<stu1[2].x){
                cout<<stu1[2].x+stu1[1].x2<<endl;
            }else{
                if(stu1[1].x2>stu1[2].x2){
                    cout<<stu1[1].x+stu1[1].x2<<endl;
                }else if(stu1[1].x2<stu1[2].x2){
                    cout<<stu1[2].x+stu1[2].x2<<endl;
                }else{
                    cout<<stu1[1].x+stu1[2].x2<<endl;
                }
            }
        }
    }



    return 0;
}
