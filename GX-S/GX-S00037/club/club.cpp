#include<bits/stdc++.h>
using namespace std;
struct myd{
    int m1,m2,m3;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.ans","w",stdout);
    int t,n;
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>n;
        myd c[n];
        int ans1 = 0,ans2 = 0,ans3 = 0,num1 = 0,num2 = 0,num3 = 0,b1 = 1e9,b2 = 1e9,b3 = 1e9;
        for(int u = 0; u<3;u++){
            for(int j = 0; j < n; j++){
                cin>>c[j].m1>>c[j].m2>>c[j].m3;
                int d = max(c[j].m1,c[j].m2,c[j].m3);
                if(d == c[j].m1){
                    for(int k = 0;k < j;k++){
                        if(c[k].m1 <= d && c[k].m1 == b1){
                            if(num1 == 3){
                                ans1-=c[k].m1;
                                c[k].m1 = 0;
                            }
                            else{
                                num1++;
                            }
                            ans1+=d;
                            b1 = min(b1,d);

                        }
                    }

                }
                else if(d == c[j].m2){
                    for(int k = 0;k < j;k++){
                        if(c[k].m2 <= d && c[k].m2 == b2){
                            if(num2 == 3){
                                ans2-=c[k].m2;
                                c[k].m2 = 0;
                            }
                            else{
                                num2++;
                            }
                            ans2+=d;
                            b2 = min(b2,d);

                        }
                    }

                }
                if(d == c[j].m3){
                    for(int k = 0;k < j;k++){
                        if(c[k].m3 <= d && c[k].m3 == b3){
                            if(num3 == 3){
                                ans3-=c[k].m3;
                                c[k].m3 = 0;
                            }
                            else{
                                num3++;
                            }
                            ans3+=d;
                            b3 = min(b3,d);

                        }
                    }

                }

            }

        }
    cout<<ans1+ans2+ans3<<endl;
    }
    return 0;
}
