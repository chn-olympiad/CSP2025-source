#include<bits/stdc++.h>
using namespace std;
int T,n,num[4],ans[4],ans_all=0;
struct student{
    int a[4];
    int cha_e;
}stu;
student v[4][100005];
int fst,snd,trd;

bool cmp1(student a,student b){
    return a.cha_e>b.cha_e;
}

bool cmp2(student a,student b){
    return a.cha_e>b.cha_e;
}

bool cmp3(student a,student b){
    return a.cha_e>b.cha_e;
}

int main(){
    //zhe dou sha a qwq
    //FuckCCF
    //Ren5Jie4Di4Ling5%
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> T;
    while(T--){
        ans_all=0;
        memset(num,0,sizeof(num));
        memset(ans,0,sizeof(ans));
        memset(v,0,sizeof(v));
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> stu.a[1] >> stu.a[2] >> stu.a[3];
            if(stu.a[1]>=stu.a[2]&&stu.a[1]>=stu.a[3]){
                stu.cha_e=min(stu.a[1]-stu.a[2],stu.a[1]-stu.a[3]);
                v[1][num[1]+1]=stu;
//                cout << stu.a[1] << " " << stu.a[2] << " " << stu.a[3] << " " << stu.cha_e <<endl;
                num[1]++;
            }
            else if(stu.a[2]>=stu.a[1]&&stu.a[2]>=stu.a[3]){

                stu.cha_e=min(stu.a[2]-stu.a[1],stu.a[2]-stu.a[3]);
                v[2][num[2]+1]=stu;
                num[2]++;
            }
            else if(stu.a[3]>=stu.a[2]&&stu.a[3]>=stu.a[1]){

                stu.cha_e=min(stu.a[3]-stu.a[2],stu.a[3]-stu.a[1]);
                v[3][num[3]+1]=stu;
                num[3]++;
            }
        }
        //
//        cout << num[1] << " " << num[2] << " " << num[3] << endl;
        //
        //基础投档
        //下面要大改了
        if(num[1]>num[2]&&num[1]>num[3]){
            fst=1;
            if(num[2]>num[3]){
                snd=2;
                trd=3;
            }
            else{
                snd=3;
                trd=2;
            }
        }
        else if(num[2]>num[1]&&num[2]>num[3]){
            fst=2;
            if(num[1]>num[3]){
                snd=1;
                trd=3;
            }
            else{
                snd=3;
                trd=1;
            }
        }
        else{
            fst=3;
            if(num[1]>num[2]){
                snd=1;
                trd=2;
            }
            else{
                snd=2;
                trd=1;
            }
        }


///ok
        sort(v[fst]+1,v[fst]+num[fst]+1,cmp1);
        ///kkk
        for(int i=1;i<=num[fst];i++){
//            cout << num[fst] << endl;
//            cout <<v[fst][i].a[1] << " " << v[fst][i].a[2] << " " << v[fst][i].a[3] << " " << v[fst][i].cha_e <<endl;
        }
        ///kkk
        for(int i=1;i<=num[fst];i++){
            if(ans[fst]<n/2){
                ans[fst]++;
                ans_all+=v[fst][i].a[fst];
                continue;
            }
            else{
                if(v[fst][i].a[snd]>=v[fst][i].a[trd]){
                    v[snd][num[snd]+1]=stu;
//                    cout << v[snd][num[snd]+1].a[snd] << "a" << endl;
                    num[snd]++;
                }
                else{
                    v[trd][num[trd]+1]=stu;
//                    cout << v[trd][num[trd]+1].a[fst] << endl;
//                    cout << v[fst][i].a[snd] << " " << v[fst][i].a[trd] << endl;
                    num[trd]++;
                }
            }
        }
        //
//        cout << fst << " " << ans_all << endl;
        //
        //once
        sort(v[snd]+1,v[snd]+num[snd]+1,cmp1);
        for(int i=1;i<=num[snd];i++){
//            cout << num[snd] << endl;
//            cout <<v[snd][i].a[1] << " " << v[snd][i].a[2] << " " << v[snd][i].a[3] << " " << v[snd][i].cha_e <<endl;
        }
        for(int i=1;i<=num[snd];i++){
            if(ans[snd]<n/2){
//                cout <<"awa" <<endl;
                ans[snd]++;
                ans_all+=v[snd][i].a[snd];
            }
            else{
//                cout <<"awa3" <<endl;
                v[trd][num[trd]+1]=stu;
                num[trd]++;
            }
        }
        //
//        cout << snd << " " << ans_all << endl;
        ///BUG
        sort(v[trd]+1,v[trd]+num[trd]+1,cmp1);
//        for(int i=1;i<=num[trd];i++){
//            cout << num[trd] << endl;
//            cout <<v[trd][i].a[1] << " " << v[trd][i].a[2] << " " << v[trd][i].a[3] << " " << v[trd][i].cha_e <<endl;
//        }
        for(int i=1;i<=num[trd];i++){
            ans_all = ans_all + v[trd][i].a[trd];
//            cout <<v[trd][i].a[trd];
//            cout <<"qwq" <<endl;
        }
        ///BUG
//        cout << trd << " " << ans_all << endl;
        //
        cout << ans_all << endl;
    }
    return 0;
}
