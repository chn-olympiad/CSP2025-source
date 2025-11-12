#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e5+10;
struct clwb{
    int ai1,ai2,ai3;
    int maxs = 0;//zui da de
    int maxs_idx = 0;//zui da de xia biao
    int maxx = 0;//di er da de
    int maxx_idx = 0;//di er da de xia biao
    int mins = 2e4+10;//zui xiao de
    int mins_idx = 0;//zui xiao de xia biao
}a[N];

struct clob{
    int num = 0;
    int sum = 0;
}cl[N];
bool cmp(clwb v1,clwb v2){
    if(v1.ai1==v2.ai1){
        if(v1.ai2==v2.ai2){
            return v1.ai3 > v2.ai3;
        }
        return v1.ai2 > v2.ai2;
    }
    return v1.ai1 > v2.ai1;
}
//int cl[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        memset(cl,0,sizeof(cl));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].ai1>>a[i].ai2>>a[i].ai3;
        }

        sort(a+1,a+n+1,cmp);


        for(int i=1;i<=n;i++){
            //a[i].ai1 zui da||zui xiao||zhong jian
            if(a[i].ai1>a[i].ai2&&a[i].ai1>a[i].ai3){
                a[i].maxs = a[i].ai1;
                a[i].maxs_idx = 1;
            }
            else if(a[i].ai1<a[i].ai2&&a[i].ai1<a[i].ai3){
                a[i].mins = a[i].ai1;
                a[i].mins_idx = 1;
            }
            else{
                a[i].maxx = a[i].ai1;
                a[i].maxx_idx = 1;
            }
            //a[i].ai2 zui da||zui xiao||zhong jian
            if(a[i].ai2>a[i].ai1&&a[i].ai2>a[i].ai3){
                a[i].maxs = a[i].ai2;
                a[i].maxs_idx = 2;
            }
            else if(a[i].ai2<a[i].ai1&&a[i].ai2<a[i].ai3){
                a[i].mins = a[i].ai2;
                a[i].mins_idx = 2;
            }
            else{
                a[i].maxx = a[i].ai2;
                a[i].maxx_idx = 2;
            }
            //a[i].ai3 zui da||zui xiao||zhong jian
            if(a[i].ai3>a[i].ai1&&a[i].ai3>a[i].ai2){
                a[i].maxs = a[i].ai3;
                a[i].maxs_idx = 3;
            }
            else if(a[i].ai3<a[i].ai1&&a[i].ai3<a[i].ai2){
                a[i].mins = a[i].ai3;
                a[i].mins_idx = 3;
            }
            else{
                a[i].maxx = a[i].ai3;
                a[i].maxx_idx = 3;
            }
            /*
            cout<<"a["<<i<<"].maxs:"<<a[i].maxs<<" a["<<i<<"].maxs_idx:"<<a[i].maxs_idx<<"\n";
            cout<<"a["<<i<<"].maxx:"<<a[i].maxx<<" a["<<i<<"].maxx_idx:"<<a[i].maxx_idx<<"\n";
            cout<<"a["<<i<<"].mins:"<<a[i].mins<<" a["<<i<<"].mins_idx:"<<a[i].mins_idx<<"\n";
            */
            //cout<<a[i].ai1<<" "<<a[i].ai2<<" "<<a[i].ai3;
            //cout<<endl;
        }
        //cout<<"-----------------t"<<endl;

        if(n==2){
            int max_ans = 0;
            int ans_temp1 = a[1].ai1+a[2].ai2;
            int ans_temp2 = a[1].ai1+a[2].ai3;
            int ans_temp3 = a[1].ai2+a[2].ai1;
            int ans_temp4 = a[1].ai2+a[2].ai3;
            int ans_temp5 = a[1].ai3+a[2].ai1;
            int ans_temp6 = a[1].ai3+a[2].ai2;
            max_ans = max({ans_temp1,ans_temp2,ans_temp3,ans_temp4,ans_temp5,ans_temp6});
            printf("%.d",max_ans);
            continue;
        }

        int temp = n/2;
        for(int i=1;i<=n;i++){
            if(cl[a[i].maxs_idx].num<temp){
                cl[a[i].maxs_idx].sum+=a[i].maxs;
                cl[a[i].maxs_idx].num++;
                //cout<<"cl["<<a[i].maxs_idx<<"].sum+="<<a[i].maxs<<endl;
            }
            else if(cl[a[i].maxx_idx].num<temp){
                cl[a[i].maxx_idx].sum+=a[i].maxx;
                cl[a[i].maxx_idx].num++;
                //cout<<"cl["<<a[i].maxx<<"].sum+="<<a[i].maxx<<endl;
            }
            else if(cl[a[i].mins_idx].num<temp){
                cl[a[i].mins_idx].sum+=a[i].mins;
                cl[a[i].mins_idx].num++;
                //cout<<"cl["<<a[i].mins_idx<<"].sum+="<<a[i].mins<<endl;
            }
        }



        long long ans = 0;
        for(int i=1;i<=3;i++){
            //cout<<"cl["<<i<<"]:"<<cl[i].sum<<endl;
            ans+=cl[i].sum;
        }
        printf("%.lld\n",ans);
    }

    return 0;
}
