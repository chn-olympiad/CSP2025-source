#include"algorithm"
#include"iostream"
#include"vector"
#include"algorithm"
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    std::cin>>n>>m;
    int b[2]={1,n},way[2]={-1,1};
    std::vector<int> v(n*m);
    for(int i=0;i<n*m;i++){
        std::cin>>v[i];
    }
    int sco=v[0],top=0;
    std::sort(v.begin(),v.end());
    for(int i=0;i<n*m;i++){
        if(sco==v[i]){
            top=i+1;
            break;
        }
    }
    top=n*m-top;
    int l=1,h=1;
    while(top>0){
        top--;
        if(h==b[l%2]){
            l++;
            continue;
        }
        h+=way[l%2];
    }
    printf("%d %d",l,h);
    return 0;
}
