#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int x,y,z,x_y,x_z,y_z;
}stu[100050];
bool cmp(int x,int y){
    return abs(x) < abs(y);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);//别忘打开
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int numx=0,numy=0,numz=0;
        vector<node> x;
        vector<node> y;
        vector<node> z;
        memset(stu,0,sizeof(stu));
        int ans=0;
        for(int i=0;i<n;i++){
           cin >> stu[i].x >> stu[i].y >> stu[i].z;
           stu[i].x_y=stu[i].x-stu[i].y;
           stu[i].x_z=stu[i].x-stu[i].z;
           stu[i].y_z=stu[i].y-stu[i].z;
            int maxx=-1,want=0;
            if(stu[i].x>maxx){
                want=1;
                maxx=stu[i].x;
            }
            if(stu[i].y>maxx){
                want=2;
                maxx=stu[i].y;
            }
            if(stu[i].z>maxx){
                want=3;
                maxx=stu[i].z;
            }
            if(want==1){
                numx++;
                x.push_back(stu[i]);
                ans+=stu[i].x;
            }
            else if(want==2){
                numy++;
                y.push_back(stu[i]);
                ans+=stu[i].y;
            }
            else if(want==3){
                numz++;
                z.push_back(stu[i]);
                ans+=stu[i].z;
            }
        }
        if(numx>n/2){
            int xx[200050]={},tot=0;
            for(int i=0;i<x.size();i++){
                xx[tot++]=x[i].x_y;
                xx[tot++]=x[i].x_z;
            }
            sort(xx,xx+tot,cmp);
            /*for(int i=0;i<x.size()*2;i++){
                cout << xx[i] << " ";
            }
            cout << endl;*/
             //cout << tot << endl;
            for(int i=0;i<numx-n/2;i++){
                ans-=abs(xx[i]);

            }
        }
         else if(numy>n/2){
            int yy[200050]={},tot=0;
            for(int i=0;i<y.size();i++){
                yy[tot++]=y[i].x_y;
                yy[tot++]=y[i].y_z;
            }
            sort(yy,yy+tot,cmp);
            for(int i=0;i<numy-n/2;i++){
                ans-=abs(yy[i]);
            }
        }
        else if(numz>n/2){
            int zz[200050]={},tot=0;
            for(int i=0;i<z.size();i++){
                zz[tot++]=z[i].x_z;
                zz[tot++]=z[i].y_z;
            }
            sort(zz,zz+tot,cmp);
            for(int i=0;i<numz-n/2;i++){
                ans-=abs(zz[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
//?1、2、5全对，3、4差两个点？
//password  Ren5Jie4Di4Ling5%
