#include<bits/stdc++.h>
using namespace std;
struct a{
    int a_1;
    int a_2;
    int a_3;

}b[100002];
int t;
bool cmp(a x,a y){
    if(x.a_1 >= y.a_1 and y.a_2>x.a_2){
        return y.a_2>x.a_2;
    }
    else return y.a_1<x.a_1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        int sum=0;
        int sum1=0;
        cin>>n;

        for(int j=0;j<n;j++){
            cin>>b[j].a_1>>b[j].a_2>>b[j].a_3;
        }
        if (n == 2){
            sum += max(max(b[0].a_1,b[0].a_2),max(b[0].a_2,b[0].a_3));
            sum += max(max(b[1].a_1,b[1].a_2),max(b[1].a_2,b[1].a_3));
            cout<<sum<<endl;
        }
        else{
            sort(b,b+n,cmp);
            for(int j=0;j<n/2;j++){
                sum+=b[j].a_1;
            }
            for(int j=n/2;j<n;j++){
                sum+=b[j].a_2;
            }
            for(int j=0;j<n/2;j++){
                sum1+=b[j].a_2;
            }
            for(int j=n/2;j<n;j++){
                sum1+=b[j].a_1;
            }
            sum = max(sum,sum1);
            cout<<sum<<endl;
            /*for(int j=0;j<n;j++){
                cout<<b[j].a_1<<" "<<b[j].a_2<<" "<<b[j].a_3<<endl;
            }*/
        }

    }
    return 0;
}

