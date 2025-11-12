#include <bits/stdc++.h>
using namespace std;
int t;
struct stu{
    int a,b,c;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        long long n,x=0,y=0,z=0,sum=0;
        stu p[100010];
        vector <int> a;
        vector <int> b;
        vector <int> c;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p[i].a>>p[i].b>>p[i].c;
            sum+=max(max(p[i].a,p[i].b),p[i].c);
            if(p[i].a>p[i].b){
                if(p[i].a>p[i].c){
                    x++;
                    a.push_back(i);
                }
                else{
                    z++;
                    c.push_back(i);
                }
            }
            else{
                if(p[i].b>p[i].c){
                    y++;
                    b.push_back(i);
                }
                else{
                    z++;
                    c.push_back(i);
                }
            }
        }
        if(x>n/2){
            int cha[x+10],j=0;
            for(int i=0;i<=a.size();i++){
                int id=a[i];
                j++;
                cha[j]=min(p[id].a-p[id].c,p[id].a-p[id].b);
            }
            sort(cha+1,cha+x+1);
            for(int i=1;i<=x-n/2;i++){
                sum-=cha[i];
            }
            cout<<sum<<endl;
        }
        else if(y>n/2){
            int cha[y+10],j=0;
            for(int i=0;i<b.size();i++){
                int id=b[i];
                j++;
                cha[j]=min(p[id].b-p[id].c,p[id].b-p[id].a);
            }
            sort(cha+1,cha+y+1);
            for(int i=1;i<=y-n/2;i++){
                sum-=cha[i];
            }
            cout<<sum<<endl;
        }
        else if(z>n/2){
            int cha[z+10],j=0;
            for(int i=0;i<c.size();i++){
                int id=c[i];
                j++;
                cha[j]=min(p[id].c-p[id].a,p[id].c-p[id].b);
            }
            sort(cha+1,cha+z+1);
            for(int i=1;i<=z-n/2;i++){
                sum-=cha[i];
            }
            cout<<sum<<endl;
        }
        else cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
