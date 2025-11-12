#include<bits/stdc++.h>
using namespace std;
int main(){
    FILE* fi=NULL,*fo=NULL;
    fi=fopen("seat.in","rr");
    fo=fopen("seat.out","wr");
    int n,m;
    fscanf(fi,"%d%d",&n,&m);
    int a[n*m];
    for(int i=0;i<n*m;++i){
        fscanf(fi,"%d",&a[i]);
    }
    int xr=a[0];
    sort(a,a+n*m,[](const int & a,const int & b)->bool{
        return a>b;
    });
    int y=1,x=1,cnt=0;bool b=0;
    for(int i=0;i<n;++i){
        if(b){for(int j=0;j<m;++j){
            if(a[cnt]==xr){
                fprintf(fo,"%d %d",x,y);
                fclose(fi);
                fclose(fo);
                return 0;
            }
            ++cnt;
            ++y;
        }}else{for(int j=m-1;j>=0;--j){
            if(a[cnt]==xr){
                fprintf(fo,"%d %d",x,y);
                fclose(fi);
                fclose(fo);
                return 0;
            }
            ++cnt;
            --y;
        }}
        b=!b;
        if(b) y=m;
        else y=1;
        ++x;
    }
    fprintf(fo,"%d %d",x,y);
    fclose(fi);
    fclose(fo);
    return 0;
}
