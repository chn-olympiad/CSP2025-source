#include<bits/stdc++.h>
using namespace std;
struct worker{
    int num,f,s,l;
}arr1[100005],arr2[100005],arr3[100005];
bool compare1(worker a,worker b){
    return a.f>b.f;
}
bool compare2(worker a,worker b){
    return a.s>b.s;
}
bool compare3(worker a,worker b){
    return a.l>b.l;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int h=0;h<t;h++){
        int n;
        long long int cnt=0;
        cin>>n;
        bool flag[100005];//true kong flase feikong
        for(int i=0;i<100005;i++) flag[i]=true;
        int tmp[100005]={};
        for(int i=0;i<n;i++){
            arr1[i].num=i;
            arr2[i].num=i;
            arr3[i].num=i;
            cin>>arr1[i].f>>arr1[i].s>>arr1[i].l;
            arr2[i].f=arr1[i].f;
            arr2[i].s=arr1[i].s;
            arr2[i].l=arr1[i].l;
            arr3[i].f=arr1[i].f;
            arr3[i].s=arr1[i].s;
            arr3[i].l=arr1[i].l;

        }
        int a1=0;
        sort(arr1,arr1+n,compare1);
        while(a1<n/2){
            cnt+=arr1[a1].f;
            flag[arr1[a1].num]=false;
            tmp[arr1[a1].num]=1;
            a1++;
        }
        sort(arr2,arr2+n,compare2);
        int a2=0,c=0;
        while(c<n/2){
            if(a2>n)break;
            if(flag[arr2[a2].num]){
                cnt+=arr2[a2].s;
                flag[arr2[a2].num]=false;
                tmp[arr2[a2].num]=2;
                c++;
                a2++;
                continue;
            }
            if(arr2[a2].f<arr2[a2].s){
                cnt-=arr2[a2].f;
                cnt+=arr2[a2].s;
                tmp[arr2[a2].num]=2;
                a2++;
                c++;
                while(flag[arr1[a1].num]==false && a1<n) a1++;
                cnt+=arr1[a1].f;
            }else{
                int linshi=cnt;
                a2++;
            }
        }

        sort(arr3,arr3+n,compare3);
        int a3=0;
        c=0;
        while(c<n/2){
            if(a3>n)break;
            if(flag[arr3[a3].num]){
                cnt+=arr3[a3].l;
                flag[arr3[a3].num]=false;
                tmp[arr3[a3].num]=2;
                c++;
                a3++;
                //cout<<cnt<<" "<<c<<endl;
                continue;
            }
            if(tmp[arr3[a3].num]==1 && arr3[a3].f<arr3[a3].l){
                cnt-=arr3[a3].f;
                cnt+=arr3[a3].l;
                tmp[arr3[a3].num]=3;
                a3++;
                c++;
                while(flag[arr1[a1].num]==false && a1<n) a1++;
                cnt+=arr1[a1].f;
            }else if(tmp[arr3[a3].num]==2 && arr3[a3].s<arr3[a3].l){
                cnt-=arr3[a3].s;
                cnt+=arr3[a3].l;
                tmp[arr3[a3].num]=3;
                a3++;
                c++;
                while(flag[arr2[a2].num]==false && a2<n) a2++;
                cnt+=arr2[a2].s;
            }else{
                a3++;
            }

            //cout<<cnt<<" "<<c<<endl;
        }

        cout<<cnt<<endl;
    }
    return 0;
}
