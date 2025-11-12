#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int z=0;z<t;z++){
        int asum=0,bsum=0,csum=0;
        struct s{
            int id;
            bool use=true;
            int num;
            char st;
        };
        cin>>n;
        int att=n/2,btt=n/2,ctt=n/2;
        s q[3*n];
        for(int j=0;j<3*n;j+=3){
            cin>>q[j].num;
            q[j].id=j;
            q[j].st='a';
            cin>>q[j+1].num;
            q[j+1].id=j;
            q[j+1].st='b';
            cin>>q[j+2].num;
            q[j+2].id=j;
            q[j+2].st='c';
        }
        for(int j=0;j<3*n;j+=3){
            cout<<n<<' '<<q[j].num<<' '<<q[j+1].num<<' '<<q[j+2].num<<' '<<endl;
        }
        for(int i=0;i<3*n;i++){
            for(int j=0;j<(3*n)-1;j++){
                if(q[j].num<q[j+1].num){
                    swap(q[j],q[j+1]);
                }
            }
        }
        int t1=n;
        int i1=0;
        while(t1>0){
            if(q[i1].st=='a'&&q[i1].use!=false&&att>0){
                asum+=q[i1].num;
                for(int j=0;j<3*n;j++){
                    if(q[j].id==q[i1].id){
                        q[j].use=false;
                    }
                }
                t1--;
                att--;
            }
            if(q[i1].st=='b'&&q[i1].use!=false&&btt>0){
                bsum+=q[i1].num;
                for(int j=0;j<3*n;j++){
                    if(q[j].id==q[i1].id){
                        q[j].use=false;
                    }
                }
                t1--;
                btt--;
            }
            if(q[i1].st=='c'&&q[i1].use!=false&&ctt>0){
                csum+=q[i1].num;
                for(int j=0;j<3*n;j++){
                    if(q[j].id==q[i1].id){
                        q[j].use=false;
                    }
                }
                t1--;
                ctt--;
            }
            i1++;
        }
        cout<<asum+bsum+csum<<endl;
    }
}
