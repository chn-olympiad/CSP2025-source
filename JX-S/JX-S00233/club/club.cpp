#include <bits/stdc++.h>;
using namespace std;
const int MAXN=100001;
int t;
struct student{
    int one,two,three;
}a[MAXN];
bool cmp1(student x,student y){
    return x.one>y.one;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n,sum1,sum2,sum3;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].one>>a[i].two>>a[i].three;
            if(a[i].one>a[i].two&&a[i].one>a[i].three)
                sum1++;
            else if(a[i].two>a[i].one&&a[i].two>a[i].three)
                sum2++;
            else if(a[i].three>a[i].one&&a[i].three>a[i].two)
                sum3++;
        }
        int num1=0,num2=0,num3=0,num=0;
        if(sum1<=n/2&&sum2<=n/2&&sum3<=n/2){
            for(int i=1;i<=n;i++){
                   if(a[i].one>a[i].two&&a[i].one>a[i].three){
                   num1+=a[i].one;
                   }
            else if(a[i].two>a[i].one&&a[i].two>a[i].three){
                   num2+=a[i].two;
                   }
            else if(a[i].three>a[i].one&&a[i].three>a[i].two){
                   num3+=a[i].three;
                   }
        }
             num=num1+num2+num3;
            }
            cout<<num<<endl;
            continue;
                }
        return 0;
        }

