#include<bits/stdc++.h>
using namespace std;
struct stu{
    int x,y,z;
};stu n[100000];
bool cmp1(stu a,stu b){
    return a.x+a.y+a.z>b.x+b.y+b.z;
}
bool cmp2(stu a,stu b){
    return a.x+a.y+a.z<b.x+b.y+b.z;
}
int fun(stu a){
    return max({a.x,a.y,a.z});
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int g;
        scanf("%d",&g);
        for(int i=0;i<g;i++){
            scanf("%d%d%d",&n[i].x,&n[i].y,&n[i].z);
        }
        sort(n,n+g,cmp1);
        int rs[3]={0,0,0},a1=0,a2=0;
        for(int i=0;i<g;i++){
            if(fun(n[i])==n[i].x){
                rs[0]++;
                if(rs[0]<=(g/2)){
                    a1+=n[i].x;
                }
                else{
                    rs[0]--;
                    if(n[i].y>=n[i].z){
                        rs[1]++;
                        if(rs[1]<=(g/2)) a1+=n[i].y;
                        else{
                            rs[1]--;
                            rs[2]++;
                            a1+=n[i].z;
                        }
                    }
                    else {
                        rs[2]++;
                        if(rs[2]<=(g/2)) a1+=n[i].z;
                        else{
                            rs[2]--;
                            rs[1]++;
                            a1+=n[i].y;
                        }
                    }
                }
            }
            else if(fun(n[i])==n[i].y){
                rs[1]++;
                if(rs[1]<=(g/2)){
                    a1+=n[i].y;
                }
                else{
                    rs[1]--;
                    if(n[i].x>=n[i].z){
                        rs[0]++;
                        if(rs[0]<=(g/2)) a1+=n[i].x;
                        else{
                            rs[0]--;
                            rs[2]++;
                            a1+=n[i].z;
                        }
                    }
                    else {
                        rs[2]++;
                        if(rs[2]<=(g/2)) a1+=n[i].z;
                        else{
                            rs[2]--;
                            rs[1]++;
                            a1+=n[i].y;
                        }
                    }
                }
            }
            else{
                rs[2]++;
                if(rs[2]<=(g/2)){
                    a1+=n[i].z;
                }
                else{
                    rs[2]--;
                    if(n[i].x>=n[i].y){
                        rs[0]++;
                        if(rs[0]<=(g/2)) a1+=n[i].x;
                        else{
                            rs[0]--;
                            rs[1]++;
                            a1+=n[i].y;
                        }
                    }
                    else {
                        rs[1]++;
                        if(rs[1]<=(g/2)) a1+=n[i].y;
                        else{
                            rs[1]--;
                            rs[0]++;
                            a1+=n[i].x;
                        }
                    }
                }
            }
        }
        rs[0]=0;
        rs[1]=0;
        rs[2]=0;
        sort(n,n+g,cmp2);
        for(int i=0;i<g;i++){
            if(fun(n[i])==n[i].x){
                rs[0]++;
                if(rs[0]<=(g/2)){
                    a2+=n[i].x;
                }
                else{
                    rs[0]--;
                    if(n[i].y>=n[i].z){
                        rs[1]++;
                        if(rs[1]<=(g/2)) a2+=n[i].y;
                        else{
                            rs[1]--;
                            rs[2]++;
                            a2+=n[i].z;
                        }
                    }
                    else {
                        rs[2]++;
                        if(rs[2]<=(g/2)) a2+=n[i].z;
                        else{
                            rs[2]--;
                            rs[1]++;
                            a2+=n[i].y;
                        }
                    }
                }
            }
            else if(fun(n[i])==n[i].y){
                rs[1]++;
                if(rs[1]<=(g/2)){
                    a2+=n[i].y;
                }
                else{
                    rs[1]--;
                    if(n[i].x>=n[i].z){
                        rs[0]++;
                        if(rs[0]<=(g/2)) a2+=n[i].x;
                        else{
                            rs[0]--;
                            rs[2]++;
                            a2+=n[i].z;
                        }
                    }
                    else {
                        rs[2]++;
                        if(rs[2]<=(g/2)) a2+=n[i].z;
                        else{
                            rs[2]--;
                            rs[1]++;
                            a2+=n[i].y;
                        }
                    }
                }
            }
            else{
                rs[2]++;
                if(rs[2]<=(g/2)){
                    a2+=n[i].z;
                }
                else{
                    rs[2]--;
                    if(n[i].x>=n[i].y){
                        rs[0]++;
                        if(rs[0]<=(g/2)) a2+=n[i].x;
                        else{
                            rs[0]--;
                            rs[1]++;
                            a2+=n[i].y;
                        }
                    }
                    else {
                        rs[1]++;
                        if(rs[1]<=(g/2)) a2+=n[i].y;
                        else{
                            rs[1]--;
                            rs[0]++;
                            a2+=n[i].x;
                        }
                    }
                }
            }
        }
        printf("%d\n",max(a1,a2));
    }
    return 0;
}
