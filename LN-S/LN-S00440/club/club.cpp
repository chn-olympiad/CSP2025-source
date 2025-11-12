#include<bits/stdc++.h>
using namespace std;
int n;
struct satisfaction{
    int x;
    int y;
    int z;
    int maxx;
    int nation;
}a[1000011];
int cx,cy,cz;
int satis=0;
bool cmp(satisfaction o,satisfaction p){
    return o.maxx<p.maxx;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int time;
    cin>>time;
    for(int i=1;i<=time;i++){
        satis=0;
        cx=0;
        cy=0;
        cz=0;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j].x>>a[j].y>>a[j].z;
            a[j].maxx=max(a[j].x,max(a[j].y,a[j].z));
            if(a[j].x>a[j].y){
                if(a[j].x>a[j].z){
                    a[j].nation=1;
                }
                if(a[j].z>a[j].x){
                    a[j].nation=3;
                }
            }
            else{
                if(a[j].y<a[j].z){
                    a[j].nation=3;
                }
                if(a[j].y>a[j].z){
                    a[j].nation=2;
                }
            }
        }
        sort(a+1,a+n+1,cmp);
        cx=0;
        cy=0;
        cz=0;
        int sum=n;
        while(n){
            if(a[n].nation==1&&cx<(sum/2)){
                cx++;
                satis+=a[n].x;
                //cout<<2<<" ";
            }
            else if(a[n].nation==2&&cy<(sum/2)){
                cy++;
                satis+=a[n].y;
                //cout<<2<<" ";
            }
            else if(a[n].nation==3&&cz<(sum/2)){
                cz++;
                satis+=a[n].z;
                //cout<<3<<" ";
            }
            else if(cy<(sum/2)&&(max(a[n].x,a[n].y)==a[n].y||max(a[n].z,a[n].x)==a[n].y)){
                cy++;
                satis+=a[n].y;
            }
            else if(cx<(sum/2)&&(max(a[n].x,a[n].y)==a[n].x||max(a[n].z,a[n].x)==a[n].x)){
                cx++;
                satis+=a[n].x;
            }
            else if(cz<(sum/2)&&(max(a[n].y,a[n].z)==a[n].z||max(a[n].z,a[n].x)==a[n].z)){
                cz++;
                satis+=a[n].z;
            }
            n--;
        }
        cout<<satis<<endl;
    }
    return 0;
}
