#include <bits/stdc++.h>
using namespace std;
struct greaty{
    int a1;
    int a2;
    int a3;
};
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t=0;
    cin>>t;
    while(t>0){
    	t--;
        int n=0,sum=0,k1=0,k2=0,k3=0;
        cin>>n;
        greaty list[10010];
        int delo[4][10010];
        for(int i=1;i<=3;i++){
            for(int j=0;j<n;j++){
                delo[i][j]=0x3f3f3f3f;
            }
        }
        for(int i=0;i<n;i++){
            cin>>list[i].a1>>list[i].a2>>list[i].a3;
        }

        for(int i=0;i<n;i++){
            int o=max(list[i].a1,max(list[i].a2,list[i].a3));
            int oc;
            if(o==list[i].a1){
                oc=max(list[i].a2,list[i].a3);
                k1++;
                sum+=o;
                delo[1][i]=o-oc;
            }
            else if(o==list[i].a2){
                oc=max(list[i].a1,list[i].a3);
                k2++;
                sum+=o;
                delo[2][i]=o-oc;
            }
            else{
                oc=max(list[i].a2,list[i].a1);
                k3++;
                sum+=o;
                delo[3][i]=o-oc;
            }
        }
        int change[10010];
        if(k1>n/2){
            for(int i=0;i<n;i++){
                change[i]=delo[1][i];
            }
            sort(change,change+n);
            int f=0;
            while(k1>n/2){
                k1--;
                sum=sum-change[f];
                f++;
                }
            }
        if(k2>n/2){
            for(int i=0;i<n;i++){
                change[i]=delo[2][i];
            }
            sort(change,change+n);
            int f=0;
            while(k2>n/2){
                k2--;
                sum=sum-change[f];
                f++;
                }
            }
        if(k3>n/2){
            for(int i=0;i<n;i++){
                change[i]=delo[3][i];
            }
            sort(change,change+n);
            int f=0;
            while(k3>n/2){
                k3--;
                sum=sum-change[f];
                f++;
            }
        }
        cout<<sum<<endl;
    }
	return 0;
}

