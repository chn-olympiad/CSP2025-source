#include <bits/stdc++.h>
using namespace std;

struct qqq{
    int glad1;
    int glad2;
    int glad3;
};

bool cmp1(qqq x,qqq y){
    return x.glad1>y.glad1;
}

bool cmp2(qqq x,qqq y){
    return x.glad2>y.glad2;
}

bool cmp3(qqq x,qqq y){
    return x.glad3>y.glad3;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin >> t;

    while(t--){
        qqq a[100005]={};
        int person[4]={};
        int ans=0;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i].glad1 >> a[i].glad2 >> a[i].glad3;

            if(a[i].glad1>=a[i].glad2&&a[i].glad1>=a[i].glad3){
                ans+=a[i].glad1;
                person[1]++;
            }
            else if(a[i].glad2>a[i].glad1&&a[i].glad2>a[i].glad3){
                ans+=a[i].glad2;
                person[2]++;
            }
            else if(a[i].glad3>a[i].glad2&&a[i].glad3>a[i].glad1){
                ans+=a[i].glad3;
                person[3]++;
            }

        }

        while(person[1]>n/2||person[2]>n/2||person[3]>n/2){
            if(person[1]>n/2){
                sort(a+1,a+1+n,cmp1);
                for(int j=n/2;j<=person[1];j++){
                    if(a[j].glad2>=a[j].glad3){
                        ans-=a[j].glad1;
                        ans+=a[j].glad2;
                        a[j].glad1=0;
                        person[1]--;
                        person[2]++;
                    }
                    else{
                        ans-=a[j].glad1;
                        ans+=a[j].glad3;
                        a[j].glad1=0;
                        person[1]--;
                        person[3]++;
                    }
                }
            }

            if(person[2]>n/2){
                sort(a+1,a+1+n,cmp2);
                for(int j=n/2;j<=person[2];j++){
                    if(a[j].glad1<=a[j].glad3){
                        ans-=a[j].glad2;
                        ans+=a[j].glad1;
                        a[j].glad2=0;
                        person[2]--;
                        person[1]++;
                    }
                    else{
                        ans-=a[j].glad2;
                        ans+=a[j].glad3;
                        a[j].glad2=0;
                        person[2]--;
                        person[3]++;
                    }
                }
            }

            if(person[3]>n/2){
                sort(a+1,a+1+n,cmp3);
                for(int j=n/2;j<=person[3];j++){
                    if(a[j].glad2>=a[j].glad3){
                        ans-=a[j].glad3;
                        ans+=a[j].glad2;
                        a[j].glad3=0;
                        person[3]--;
                        person[2]++;
                    }
                    else{
                        ans-=a[j].glad3;
                        ans+=a[j].glad1;
                        a[j].glad3=0;
                        person[3]--;
                        person[1]++;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
