#include<bits/stdc++.h>
using namespace std;
struct a{
    long long a,b,c,x[4],m[4];
}a[100002];
long long t,n,q=0,zzz,z=0,s[5],sss[5][5];
int main(){
    ifstream fin("club.in");
    ofstream fout("club.out");

    fin>>t;

    while(q<t)
    {
        fin>>n;
        s[1]=0;
        s[2]=0;
        s[3]=0;

        for(int i=0;i<n;i++)
        {
            fin>>a[i].a>>a[i].b>>a[i].c;
            sss[0][1]=a[i].a;
            sss[1][1]=a[i].b;
            sss[2][1]=a[i].c;
            sss[0][0]=1;
            sss[1][0]=2;
            sss[2][0]=3;
            for(int j=0;j<=2;j++)
            {
                for(int o=0;o<=2-j;o++)
                {
                    if(sss[o][1]<sss[o+1][1])
                    {
                        zzz=sss[o][1];
                        sss[o][1]=sss[o+1][1];
                        sss[o+1][1]=zzz;
                    }
                }
            }
            a[i].m[1]=sss[0][1];
            a[i].m[2]=sss[2][1];
            a[i].m[3]=sss[3][1];
            a[i].x[1]=sss[0][0];
            a[i].x[2]=sss[2][0];
            a[i].x[3]=sss[3][0];
            }
//1
        for(int j=0;j<n+2;j++){
            for(int o=0;o<=n-j+1;o++)
            {    if(a[o].m[1]<a[o+1].m[1])
                {
                    a[100001]=a[o];
                    a[o]=a[o+1];
                    a[o+1]=a[100001];
                }

            }
        }
        for(int w=0;w<=n+1;w++)
        {
            if(s[a[w].x[1]]<=n/2){
            z+=a[w].m[1];
            s[a[w].x[1]]++;
            a[w]=a[100002];
           }
           //2
        }
        for(int j=0;j<n+2;j++){
            for(int o=0;o<=n-j+1;o++)
            {    if(a[o].m[2]<a[o+1].m[2])
                {
                    a[100001]=a[o];
                    a[o]=a[o+1];
                    a[o+1]=a[100001];
                }

            }
        }
        for(int w=0;w<=n+1;w++)
        {
            if(s[a[w].x[2]]<=n/2){
            z+=a[w].m[2];
            s[a[w].x[2]]++;
            a[w]=a[100002];
           }
        }
        //3
        for(int j=0;j<n+2;j++){
            for(int o=0;o<=n-j+1;o++)
            {    if(a[o].m[3]<a[o+1].m[3])
                {
                    a[100001]=a[o];
                    a[o]=a[o+1];
                    a[o+1]=a[100001];
                }

            }
        }
        for(int w=0;w<=n+1;w++)
            z+=a[w].m[3];
   //    cout<<z<<endl;

        fout<<z<<endl;
        z=0;

        q++;
    }
    fin.close();
    fout.close();
    return 0;
}
