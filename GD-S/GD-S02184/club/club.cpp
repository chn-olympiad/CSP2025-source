#include<bits/stdc++.h>
//#include<al>
using namespace std;
struct guy{
    int A,B,C,delta_x,_max;char work_for;
};
char which;
bool cmp(const guy&a,const guy&b){
    return a.delta_x<b.delta_x;
}
vector<guy>p;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n;cin>>T;
    int A=0,B=0,C=0,best;
    int tmp1,tmp2,tmp3;
    while(T--){
        cin>>n;
        p.clear();
        p.resize(n);
        A=0;B=0;C=0;best=0;
        for(auto&i:p){
            scanf("%d %d %d",&i.A,&i.B,&i.C);
            i._max=max(i.A,max(i.B,i.C));
            tmp2=i.A+i.B+i.C;
            tmp3=min(i.A,min(i.B,i.C));
            i.delta_x=i._max-(tmp2-tmp3-i._max);
            i.work_for=(i.A>i.B&&i.A>i.C)?'A':(i.B>i.A&&i.B>i.C?'B':'C');
            switch (i.work_for)
            {
            case 'A':
                A++;
                break;
            case 'B':
                B++;
                break;
            default:
                C++;
                break;
            }
        }
        int _max_=max(A,max(B,C));
        for(auto&i:p)best+=i._max;
        if(_max_>n/2){
            which=(A>B&&A>C)?'A':(B>A&&B>C?'B':'C');
            int minus=max(A,max(B,C))-n/2;
            for(int i=0,j=0;j<_max_;i++){
                if(p[i].work_for==which)p[j++]=p[i];
            }
            
            sort(p.begin(),p.begin()+_max_,cmp);
            for(int i=0;i<_max_;i++)best-=p[i].delta_x;
        }
        cout<<best<<endl;
        
    }
    
    fclose(stdin);fclose(stdout);
}