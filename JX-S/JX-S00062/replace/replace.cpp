#include <iostream>
using namespace std;
const int N = 2e5+10;
struct ww{
    string si1,si2;
}a[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].si1>>a[i].si2;
    }
    while(q--){
        string tj1,tj2;
        cin>>tj1>>tj2;
        int s_a = 0;
        int s_b = 0;
        for(int i=0;i<tj1.size;i++){
            if(tj1[i]=='a'){
                s_a++;
            }
            else if(tj1[i]=='b'){
                s_b++;
            }
        }
        if(s_a==tj1.size||s_b==1){
            cout<<n<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }


    return 0;
}
