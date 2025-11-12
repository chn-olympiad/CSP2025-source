#include<bits/stdc++.h>
using namespace std;

int main(){
    fropen("club.in","r","in")
    fropen("club.out","w","out")
int t,n;
int a[5][2][3];
int L=3,l=3;

cin>>t>>n;
for(int z=0;z<t;z++){
    for(int x=0;x<n;x++){
        for(int y=0;y<L;y++){
            cin>>a[z][x][y];
            }
        }
    }
if(n=2){
    for(int z=0;z<t;z++){
    int sum=0;
        for(int x=0;x<L;x++){int sum1=0;
            for(int y=0;y<L;y++){

                sum1=a[z][1][x]+a[z][2][y];
                if(y==x){sum1=sum;}
                if(sum1>=sum){
                    sum=sum1;
                }
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}

return 0;
}
