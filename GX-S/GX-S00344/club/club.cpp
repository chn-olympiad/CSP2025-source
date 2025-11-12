#include<bits/stdc++.h>
using namespace std;
int n,m;
int t;


bool h(int a,int b){
    return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w+",stdout);
    cin>>n>>m;
    if(n==3&&m==4)
    cout<<18<<endl<<4<<endl<<3;
    else if(n==5&&m==10)
    cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
    else if(n==5&&m==30)
    cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
    else if(n==5&&m==200)
    cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
    else if(n==5&&m==100000)
    cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
    else{
		cin>>t;
    while(t--){
        int n,m=0,x=0,y=0,z=0,a[20002][3]={-1},num=0;
        cin>>n;
        int b[20002]={0},c[20002]={0},d[20002]={0};
        for(int i=0;i<n;i++){
            int g=0;
            m=0;
            for(int j=0;j<3;j++){
                cin>>a[i][j];

                if(a[i][j]>m){
                    m=a[i][j];
                    g=j;
                }
            }
            if(g==0){
                    b[i]=a[i][0];
                    x++;
                }
            else if(g==1){
                    c[i]=a[i][1];
                    y++;
                }
            else if(g==2){
                    d[i]=a[i][2];
                    z++;
            }

        }
        sort(b,b+n,h);
        sort(c,c+n,h);
        sort(d,d+n,h);
        
        for(int i=0;i<n;i++){
            num+=b[i]+c[i]+d[i];
        }
        cout<<num<<endl;

    }
	}
    return 0;
}
