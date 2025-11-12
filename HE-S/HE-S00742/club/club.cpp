#include<bits/stdc++.h>
using namespace std;
int t,n,mx,fj12,fj23,ywbut;
long long zong,ans[4];//my[4],
struct sd{
    int st[4];
    int zsh;
    int cz;
    int dl;
    int yuanxu;
};
sd a[100005],b[100005];
void pd(int x){//pangding zuishihe de shetuan
    a[x].zsh=3;
    if(a[x].st[1]>=a[x].st[a[x].zsh]) a[x].zsh=1;
    if(a[x].st[2]>=a[x].st[a[x].zsh]) a[x].zsh=2;
    a[x].dl=a[x].st[a[x].zsh];
}
bool cmp(sd x,sd y){//an shetuan xiaodaoda shuzi dadaoxiao paixu
    if(x.zsh==y.zsh) return x.st[x.zsh]>=y.st[y.zsh];
    else return x.zsh<y.zsh;
}
bool czmp(sd x,sd y){// an chazhi xiaodaoda paixu
    return x.cz<=y.cz;
}
void bfza(){
    for(int i=0;i<n;i++){
        b[i].st[1]=a[i].st[1];
        b[i].st[2]=a[i].st[2];
        b[i].st[3]=a[i].st[3];
        b[i].zsh=a[i].zsh;
        b[i].dl=a[i].dl;
        b[i].cz=a[i].cz;
        b[i].yuanxu=i;
    }
}
void cz(int y){// jisuan chazhi
    b[y].dl=b[y].st[b[y].zsh];
    if(b[y].zsh==1){
        if(b[y].st[2]>=b[y].st[3]){
            b[y].cz=b[y].st[1]-b[y].st[2];
            b[y].st[1]=-1;
            b[y].zsh=2;
        }
        else {
            b[y].cz=b[y].st[1]-b[y].st[3];
            b[y].st[1]=-1;
            b[y].zsh=3;
        }
    }
    else if(b[y].zsh==2){
        if(b[y].st[1]>=b[y].st[3]){
            b[y].cz=b[y].st[2]-b[y].st[1];
            b[y].st[2]=-1;
            b[y].zsh=1;
        }
        else {
            b[y].cz=b[y].st[2]-b[y].st[3];
            b[y].st[2]=-1;
            b[y].zsh=3;
        }
    }
    else {
        if(b[y].st[2]>=b[y].st[1]){
            b[y].cz=b[y].st[3]-b[y].st[2];
            b[y].st[3]=-1;
            b[y].zsh=2;
        }
        else {
            b[y].cz=b[y].st[3]-b[y].st[1];
            b[y].st[3]=-1;
            b[y].zsh=1;
        }
    }
}
void fenjie(int x){
    if(x>0&&a[x].zsh!=a[x-1].zsh){
        if(a[x-1].zsh==1&&a[x].zsh==2) fj12=x;
        if(a[x-1].zsh==1&&a[x].zsh==3){
            fj12=x;
            fj23=x;
        }
        if(a[x-1].zsh==2) fj23=x;
        ywbut=1;
    }
}
int fwl(int x){//xunzhao fenjie zuijie
    if(x==1) return 0;
    else if(x==2) return fj12;
    else return fj23;
}
int fwr(int x){//xunzhao fenjie youjie
    if(x==1) return fj12;
    else if(x==2) return fj23;
    else return n;
}
void yidong(int x,int as){//jiang chazhi zuixiao de yidong,jianqu chazhi
    for(int i=0;i<n;i++) fenjie(i);
    int l=fwl(x),r=fwr(x);
    for(int i=l;i<r;i++) cz(i);
    sort(b+l,b+r,czmp);
    /*
    cout<<"paixuhou shuzu:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"chazhi "<<b[i].cz<<" zsh "<<b[i].zsh<<" shuzhi "<<b[i].st[b[i].zsh]<<" daoling "<<b[i].dl<<';'<<endl;
    }
    cout<<"zongshuwei:"<<zong<<endl;
    cout<<"jianqule:"<<b[l].cz<<endl;
    */
    zong-=b[l].cz;
    a[b[l].yuanxu].st[1]=b[l].st[1];
    a[b[l].yuanxu].st[2]=b[l].st[2];
    a[b[l].yuanxu].st[3]=b[l].st[3];
    a[b[l].yuanxu].zsh=b[l].zsh;
    a[b[l].yuanxu].cz=b[l].cz;
    ans[x]--;
    ans[a[b[l].yuanxu].zsh]++;
    a[l].dl=a[l].st[a[l].zsh];

    if(ans[a[b[l].yuanxu].zsh]>mx){
        if(as==1) yidong(a[b[l].yuanxu].zsh,2);
        else{
            zong-=b[l].dl;
            /*
            cout<<l<<endl;
            cout<<"zongshuwei:"<<zong<<endl;
            cout<<"jianqule:"<<b[l].dl<<endl;
            */
            ans[x]--;
            ans[a[b[l].yuanxu].zsh]++;
        }
    }
    bfza();
}
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
        cin>>n;
        mx=n/2;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(ans,0,sizeof(ans));
        zong =0;
        for(int i=0;i<n;i++){
            cin>>a[i].st[1]>>a[i].st[2]>>a[i].st[3];
            pd(i);
        }
        sort(a,a+n,cmp);
        /*
        cout<<"paixuhou shuzu:"<<endl;
        for(int i=0;i<n;i++){
            cout<<"zsh "<<a[i].zsh<<" shuzhi "<<a[i].st[a[i].zsh]<<" daoling "<<a[i].dl<<';'<<endl;
        }*/
        for(int i=0;i<n;i++){
            zong+=a[i].st[a[i].zsh];
            fenjie(i);
            ans[a[i].zsh]++;
        }
        if(ywbut==0){
            if(a[0].zsh==1){
                fj12=n;
                fj23=n;
            }
            if(a[0].zsh==2){
                fj12=0;
                fj23=n;
            }
        }
        /*
        cout<<"zongshuwei:"<<zong<<endl;
        cout<<"1he2 fenjie:"<<fj12<<" 2he3 fenjie:"<<fj23<<endl;
        */
        bfza();
        for(int k=1;k<4;k++){
            if(ans[k]>mx){
                while(ans[k]>mx) yidong(k,1);
            }
        }
        //zong=my[1]+my[2]+my[3];
        cout<<zong<<endl;
	}
	return 0;
}
