#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int a[100005]={0},b[100005]={0},c[100005]={0},a_people=0,b_people=0,c_people=0,decide[100005]={0},ans=0,fin[100005]={0},f,g,am_max;
        int n;
        cin>>n;
        int max_people=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            f=max(a[i],b[i]);
            g=max(b[i],c[i]);
            decide[i]=max(f,g);
            if(decide[i]==a[i])a_people++;
            else if(decide[i]==b[i])b_people++;
            else c_people++;
        }
        for(int i=1;i<=n;i++)ans+=decide[i];
        if(a_people>max_people || b_people>max_people || c_people>max_people){
            f=max(a_people,b_people);
            g=max(b_people,c_people);
            int sh_bs=max(f,g);
            for(int i=1;i<=n;i++){
                if(decide[i]==a[i])am_max=min(decide[i]-b[i],decide[i]-c[i]);
                else if(decide[i]==b[i])am_max=min(decide[i]-a[i],decide[i]-c[i]);
                else if(decide[i]==c[i])am_max=min(decide[i]-a[i],decide[i]-b[i]);
                fin[i]=am_max;
            }
            sort(fin+1,fin+n+1);
            for(int i=1;i<=sh_bs-max_people;i++)ans-=fin[i];
            cout<<ans;
        }else{
            cout<<ans;
        }
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


