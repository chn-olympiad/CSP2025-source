#include <iostrean>
using namespace std;
int main(){
    int n,m,c,r;
    cin>>n>>m;
    cin>>c>>r;
    if (c>n){
        c==(c%n);
    }
    if (r>m){
        r==(r%m);
    }
    cout <<c*r;
    return 0;
}
