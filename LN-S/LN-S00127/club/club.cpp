#include<bits/stdc++.h>
using namespace std;
int num[100005][3],num1[100005],t,n,a = 0,b = 0,c = 0,sum1 = 0,as = 0,bs = 0,cs = 0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int x = 0;x < t;x++){
        cin>>n;
        for(int y = 0;y < n;y++){
            cin>>num[x][0]>>num[x][1]>>num[x][2];
        }
        for(int z = 0;z < n;z++){
            for(int i = n;i >= 0;i--){
                if(num1[i] > 2){
                    num1[i-1] += 1;
                    num1[i] = 0;
                }else{
                    num1[i] += 1;
                }
                for(int y = 0;y < n;y++){
                    if(num1[y] == 0){
                        a++;
                        as += num[y][0];
                    }
                    if(num1[y] == 1){
                        b++;
                        bs += num[y][1];
                    }
                    if(num1[y] == 2){
                        c++;
                        cs += num[y][2];
                    }
                }
                if(a <= n/2 and b <= n/2 and c <= n/2){
                    if((as + bs + cs) > sum1){
                        sum1 = as + bs +cs;
                    }
                }
                as = 0;
                bs = 0;
                cs = 0;
            }
        }
        cout<<sum1<<endl;
    }
    return 0;
}
