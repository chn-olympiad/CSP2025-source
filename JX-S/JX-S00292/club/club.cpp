#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1e5+1;

int main();
int _main();

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        _main();
    }
}

struct per{
    int a;
    int n;
};
bool cmp(per a,per b){
    return a.a>b.a;
}
int _main(){

    int n;
    per c1[MAXN]={},c2[MAXN]={},c3[MAXN]={};
    int a[MAXN][4];
    int d[MAXN]={};
    cin>>n;
    for(int i=1;i<=n;i++){
        c1[i].n=i;
        cin>>c1[i].a;
        c2[i].n=i;
        cin>>c2[i].a;
        c3[i].n=i;
        cin>>c3[i].a;
        a[i][1]=c1[i].a;
        a[i][2]=c2[i].a;
        a[i][3]=c3[i].a;
    }
    sort(c1+1,c1+n+1,cmp);
    sort(c2+1,c2+n+1,cmp);
    sort(c3+1,c3+n+1,cmp);


    int s1=0,sn1=0,s2=0,sn2=0,s3=0,sn3=0;
    for(int i=1;i<=n;i++){
        if(sn1<n/2)
        if(d[c1[i].n]==0&&sn1<=n/2){
            s1+=c1[i].a;
            sn1++;
            d[c1[i].n]=1;
            //cout<<"c1 use"<<c1[i].n<<endl;
        }
        else{
            if(d[c1[i].n]==2){
                if(a[c1[i].n][1]>a[c1[i].n][2]){
                    //cout<<"No,c1 use"<<c1[i].n<<endl;
                    s1+=c1[i].a;
                    sn1++;
                    sn2--;
                    s2-=a[c1[i].n][2];
                    d[c1[i].n]=1;
                }
            }
            if(d[c1[i].n]==3){
                if(a[c1[i].n][1]>a[c1[i].n][3]){
                    //cout<<"No,c1 use"<<c1[i].n<<endl;
                    s1+=c1[i].a;
                    sn1++;

                    sn3--;
                    s3-=a[c1[i].n][3];
                    d[c1[i].n]=1;
                }
            }
        }
        if(d[c2[i].n]==0&&sn2<n/2){
            //cout<<"c2 use"<<c2[i].n<<endl;
            s2+=c2[i].a;
            sn2++;
            d[c2[i].n]=2;
        }
        else{
            if(d[c2[i].n]==1){
                if(a[c2[i].n][2]>a[c2[i].n][1]&&sn2<n/2){
                    //cout<<"No,c2 use"<<c2[i].n<<' '<<sn2<<endl;
                    s2+=c2[i].a;
                    sn2++;

                    sn1--;
                    s1-=a[c2[i].n][1];

                    d[c2[i].n]=2;
                }
            }
            if(d[c2[i].n]==3){
                if(a[c2[i].n][2]>a[c2[i].n][3]&&sn2<=n/2){
                    //cout<<"No,c2 use"<<c2[i].n<<endl;
                    s2+=c2[i].a;
                    sn2++;

                    sn3--;
                    s3-=a[c2[i].n][3];
                    d[c2[i].n]=2;
                }
            }
        }
if(sn3<n/2)
        if(d[c3[i].n]==0&&sn3<=n/2){
            //cout<<"c3 use"<<c3[i].n<<endl;
            s3+=c3[i].a;
            sn3++;
            d[c3[i].n]=3;
        }
        else{
            if(d[c3[i].n]==1){
                if(a[c3[i].n][3]>a[c2[i].n][1]){
                    //cout<<"No,c3 use"<<c3[i].n<<endl;
                    s3+=c3[i].a;
                    sn3++;

                    sn1--;
                    s1-=a[c3[i].n][1];
                    d[c3[i].n]=3;
                }
            }
            if(d[c3[i].n]==2){
                if(a[c3[i].n][3]>a[c2[i].n][2]){
                    //cout<<"No,c3 use"<<c3[i].n<<endl;
                    s3+=c3[i].a;
                    sn3++;

                    sn2--;
                    s2-=a[c3[i].n][2];
                    d[c3[i].n]=3;
                }
            }
        }
    }
    cout<<s1+s2+s3<<endl;
}
