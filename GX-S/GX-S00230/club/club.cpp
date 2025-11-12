#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;
    cout<<"aaa";
    int a1[1000001],a2[1000001],a3[1000001];
    while(n--){
        int pe;

        cin>>pe;
        int q=0,r,n=0;
        r=pe/2;
        int n1=0,n2=0,n3=0;
        for(int i=0;i<pe;i++){
            cin>>a1[i]>>a2[i]>>a3[i];
        }
        for(int i=0;i<pe;i++){
            if(a1[i]>a2[i] && a1[i]>a3[i] && n<=r){
                n++;
                q+=a1[i];
            }else if(a2[i]>a1[i] && a2[i]>a3[i] && n<=r){
                n++;
                q+=a2[i];
            }else if(n<=r){
                n++;
                q+=a3[i];

            }
        }
        cout<<q;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
