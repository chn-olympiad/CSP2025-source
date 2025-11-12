#include<bits/stdc++.h>
using namespace std;
main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,n;
cin>>t;

int aa=0,bb=0,cc=0;
while(t--){
        int sum=0;
    cin>>n;
    int q=n/2;
    for(int i=1;i<=n;i++){

        for(int j=3;j>=0;j--){
            int a,b,c;
            cin>>a>>b>>c;
            if(a>b>c){
            sum+=a;
            aa+=1;
        }else{
            if(a>c>b){
                sum+=a;
                aa+=1;
            }else{
                if(c>b>a){
                    sum+=c;
                    cc+=1;
                }
                if(c>a>b){
                    sum+=c;
                    cc+=1;
                }
                if(b>c>a){
                    sum+=b;
                    bb+=1;
                }
                if(b>a>c){
                    sum+=b;
                bb+=1;
                }

        }

    }


}
if(aa<=q&&bb<=q&&cc<=q){
        cout<<sum;



    }



    }
}return 0;
}
