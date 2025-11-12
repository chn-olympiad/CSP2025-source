#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int y,pp=0;
        cin>>y;
        int n[y][3]={};
        for(int p=0;p<y;p++){
            cin>>n[p][0]>>n[p][1]>>n[p][2];
            int yyy=0;
            for(int kkk=0;kkk<3;kkk++){
                if(n[p][kkk]>yyy){
                    yyy=n[p][kkk];
                }
            }
            pp+=yyy;
        }
        int h=0;
        if(y==2){
            for(int z=0;z<3;z++){
                for(int x=0;x<3;x++){
                   if(n[0][z]+n[1][x]>h&&z!=x){
                    h=n[0][z]+n[1][x];
                   }
                }
            }
            cout<<h<<endl;//break;
            //return 0;
        }
if(y!=2){
    cout<<pp<<endl;
}



    }
    return 0;
}
