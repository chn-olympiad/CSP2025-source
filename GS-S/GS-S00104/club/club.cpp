#include<bits/stdc++.h>
using namespace std;
class people{
    public:
        int first;
        int second;
        int third;
        int highest;
};
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,best[3][2]={0};
    int count=0;
    cin>>t;
    int answer[t];
    for(int q=0;q<t;q++){
    cin>>n;
    people list[n];
    for(int i=0;i<n;i++){
        cin>>list[i].first>>list[i].second>>list[i].third;
        if(list[i].first>best[0][0]){
            best[0][0]=i;
            best[0][1]=list[i].first;
        }
        if(list[i].second>best[1][0]){
            best[1][0]=i;
            best[1][1]=list[i].second;
        }
        if(list[i].third>best[2][0]){
            best[2][0]=i;
            best[2][1]=list[i].third;
        }
        list[i].highest=max(list[i].first,max(list[i].second,list[i].third));
    }
    if(best[2][1]==0){
        if(best[1][1]==0){
            int afa[n];
            for(int i=0;i<n;i++){
                afa[i]=list[i].first;
            }
            sort(&afa[0],&afa[n]);
            for(int i=n-1;i>=n/2;i--){
                count+=afa[i];
            }
            answer[q]=count;
        }
        else if(best[0][1]==0){
            int afa[n];
            for(int i=0;i<n;i++){
                afa[i]=list[i].second;
            }
            sort(&afa[0],&afa[n]);
            for(int i=n-1;i>=n/2;i--){
                count+=afa[i];
            }
            answer[q]=count;
        }
    }

    }
    for(int q=0;q<t;q++){
        cout<<answer[q]<<endl;
    }
    return 0;
}
