#include<iostream>
using namespace std;
const int maxn=100005;
int a1[maxn],a2[maxn],a3[maxn],sum;
//int maxa[maxn],a1n[maxn],a2n[maxn],a3n[maxn];
int maxx;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            maxx=0;
            cin>>a1[i]>>a2[i]>>a3[i];
            if(a1[i]<=a2[i]){
                maxx=2;
                //cout<<"&*"<<endl;
            }else if(a1[i]>a2[i]){
                maxx=1;

            }
            //cout<<a1[i]<<" "<<a2[i]<<endl;
            if(maxx==1){
                if(a3[i]>a1[i]){
                    maxx=3;
                    //cout<<"(!"<<endl;
                }
            }else{
                if(a3[i]>a2[i]){
                    maxx=3;
                    //cout<<"(!1"<<endl;
                }
            }
            //cout<<maxx<<"elb"<<endl;
            if(maxx==1){
                //maxa[i]=1;
                sum+=a1[i];
                //cout<<"a"<<endl;
            }else if(maxx==2){
                //maxa[i]=2;
                sum+=a2[i];
                //cout<<"b"<<endl;
            }else if(maxx==3){
                //maxa[i]=3;
                sum+=a3[i];
                //cout<<"c"<<endl;
            }
            //cout<<sum<<"ktj"<<endl;
        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}
