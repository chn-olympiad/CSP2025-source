#include<bits/stdc++.h>
using namespace std;
struct student{
    long long a,b,c,delta,first,second;
}stu[100005];
bool cmp(student a, student b){
    return a.delta>b.delta;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t,n,num1,num2,num3,cnt;
    cin>>t;
    for(int i = 1;i<=t;i++){
        num1 = 0;
        num2 = 0;
        num3 = 0;
        cnt = 0;
        cin>>n;
        for(int j = 1;j<=n;j++){
            cin>>stu[j].a>>stu[j].b>>stu[j].c;
            if(stu[j].a>=stu[j].b && stu[j].b>=stu[j].c){
                stu[j].first = 1;
                stu[j].second = 2;
                stu[j].delta = stu[j].a-stu[j].b;
            }
            else if(stu[j].a>=stu[j].c && stu[j].c>=stu[j].b){
                stu[j].first = 1;
                stu[j].second = 3;
                stu[j].delta = stu[j].a-stu[j].c;
            }
            else if(stu[j].b>=stu[j].a && stu[j].a>=stu[j].c){
                stu[j].first = 2;
                stu[j].second = 1;
                stu[j].delta = stu[j].b-stu[j].a;
            }
            else if(stu[j].b>=stu[j].c && stu[j].c>=stu[j].a){
                stu[j].first = 2;
                stu[j].second = 3;
                stu[j].delta = stu[j].b-stu[j].c;
            }
            else if(stu[j].c>=stu[j].a && stu[j].a>=stu[j].b){
                stu[j].first = 3;
                stu[j].second = 1;
                stu[j].delta = stu[j].c-stu[j].a;
            }
            else if(stu[j].c>=stu[j].b && stu[j].b>=stu[j].a){
                stu[j].first = 3;
                stu[j].second = 2;
                stu[j].delta = stu[j].c-stu[j].b;
            }
        }
        sort(stu+1,stu+n+1,cmp);
        for(int j = 1;j<=n;j++){
            if(stu[j].first == 1){
                if(num1 < n/2){
                    num1++;
                    cnt += stu[j].a;
                }
                else cnt += (stu[j].a-stu[j].delta);
            }
            else if(stu[j].first == 2){
                if(num2 < n/2){
                    num2++;
                    cnt += stu[j].b;
                }
                else cnt += (stu[j].b-stu[j].delta);
            }
            else if(stu[j].first == 3){
                if(num3 < n/2){
                    num3++;
                    cnt += stu[j].c;
                }
                else cnt += (stu[j].c-stu[j].delta);
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
