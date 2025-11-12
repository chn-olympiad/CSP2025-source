#include<bits/stdc++.h>
using namespace std;
struct sz{
    string a,b;
}th[200010];
bool pd(string x,string y,string z,string bt){
 //   cout<<x<<" "<<y<<" "<<z<<" "<<bt<<endl;
    string tt=x;
    for(int i=0;i<y.size();i++) tt+=y[i];
    for(int i=0;i<z.size();i++) tt+=z[i];
    if(tt==bt) return 1;
    else return 0;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>th[i].a>>th[i].b;
    }
    while(q--){
        sz bt;
        cin>>bt.a>>bt.b;
        long long t=0;
        for(int k=1;k<=n;k++){
            string x;
            for(int i=0,j=th[k].a.size()-1;j<bt.a.size();i++,j++){
                string y,z;
                int ji=i;
                while(ji<=j){
                    y+=bt.a[ji];
                    ji++;
                }
                ji=j+1;
                while(ji<bt.a.size()){
                    z+=bt.a[ji];
                    ji++;
                }
                if(y==th[k].a&&pd(x,th[k].b,z,bt.b)==1){

                    t++;
                }
                x+=bt.a[i];
            }
        }
        cout<<t<<endl;
    }
    return 0;
}
