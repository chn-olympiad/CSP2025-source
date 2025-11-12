#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,rcj,pm,c,d;
    int cj[105];
    cin >> a >> b;
    for(int i=0;i<a*b;i++){
        cin >> cj[i];
    }
    if(a==1 and b==1){
        cout << "1 1";
        return 0;
    }
    rcj=cj[0];
    sort(cj,cj+a*b+1,cmp);
    for(int i=0;i<a*b;i++){
        if(cj[i]==rcj){
            if(i==0){
                cout << "1 1";
                return 0;
            }
            pm=i+1;
            if(a==1){
                cout << pm << " " << "1";
                return 0;
            }
            else if(b==1){
                cout << "1" << " " << pm;
                return 0;
            }
            if(a==2){
                d=pm/2+pm%2;
                if(pm==1 || pm==4 || pm==5 || pm==8 || pm==9 || pm==12 || pm==13 || pm==16 || pm==17 || pm==20){
                    cout << "1" << " " << d;
                    return 0;
                }
                else{
                    cout << "2" << " " << d;
                    return 0;
                }
            }
            if(a==10){
                if(pm/10==1){
                    cout << pm%b << "1";
                    return 0;
                }
                else{
                    cout << 10-(pm%b) << "2";
                    return 0;
                }
            }
        }

    }
    return 0;
}
