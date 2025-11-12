#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int T;
struct node{
    int one=0,two=0,tre=0,best=0,index=0;
}a[N],pone[N],ptwo[N],ptre[N];

bool cmp1(node x,node y){
    return x.one>y.one;
}
bool cmp2(node x,node y){
    return x.two>y.two;
}
bool cmp3(node x,node y){
    return x.tre>y.tre;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0);
    cin>>T;
    while(T--){
        int n;
        int ans=0,p1=0,p2=0,p3=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){//in
            scanf("%d %d %d",&a[i].one,&a[i].two,&a[i].tre);
            a[i].index=i;
        }
        for(int i=1;i<=n;i++){//best
            if(a[i].one>=a[i].two&&a[i].one>=a[i].tre) {a[i].best=1;pone[i]=a[i];}
            if(a[i].two>=a[i].one&&a[i].two>=a[i].tre) {a[i].best=2;ptwo[i]=a[i];}
            if(a[i].tre>=a[i].one&&a[i].tre>=a[i].two) {a[i].best=3;ptre[i]=a[i];}
        }
		/**for(int i=1;i<=n;i++){//isbest
        	cout<<"Best:"<<a[i].best<<" ";
		}
		cout<<'\n';**/
        sort(pone+1,pone+n+1,cmp1);//sort
        sort(ptwo+1,ptwo+n+1,cmp2);
        sort(ptre+1,ptre+n+1,cmp3);
        /*for(int i=1;i<n;i++){

        	cout<<pone[i].index<<"H\n";
		}*/
        for(int i=1;i<=n;i++){//chuliA
            if(p1<n/2&&pone[i].best==1){//chulip1
                a[pone[i].index].best=-1;
                pone[i].best=-1;//chuliguole
                p1++;
                ans+=pone[i].one;
                //cout<<"I'm"<<pone[i].one<<":"<<"I join in 1"<<'\n';
                pone[i].one=-1;
            }
            if(p2<n/2&&ptwo[i].best==2){//chuli2
            	a[ptwo[i].index].best=-1;
                ptwo[i].best=-1;//chuliguole
                p2++;
                ans+=ptwo[i].two;
            	//cout<<"I'm"<<ptwo[i].two<<":"<<"I join in 2"<<'\n';
            	ptwo[i].two=-1;
            }
            if(p3<n/2&&ptre[i].best==3){//chuli3
                a[ptre[i].index].best=-1;
                ptre[i].best=-1;
                p3++;
                ans+=ptre[i].tre;
                //cout<<"I'm"<<ptre[i].tre<<":"<<"I join in 3"<<'\n';
                ptwo[i].two=-1;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i].best!=-1){
                //cout<<"False"<<" "<<a[i].index<<'\n';
                if(p1<n/2&&a[i].one>=a[i].two&&a[i].one>=a[i].tre){
                    a[i].best=-1;//chuliguole
                    p1++;
                    ans+=a[i].one;
                    //cout<<"I'mF "<<pone[i].one<<":"<<"I join in 1"<<'\n';
                    continue;
                }
                if(p2<n/2&&a[i].two>=a[i].one&&a[i].two>=a[i].tre){
                    a[i].best=-1;//chuliguole
                    p2++;
                    ans+=a[i].two;
                    //cout<<"I'mF "<<ptwo[i].two<<":"<<"I join in 2"<<'\n';
                    continue;
                }
                if(p3<n/2&&a[i].best==3){
                    a[i].best=-1;//chuliguole
                    p3++;
                    ans+=a[i].tre;
                    //cout<<"I'mF "<<ptre[i].tre<<":"<<"I join in 3"<<'\n';
                    continue;
                }
            }
        }
        /**TODO
        for(int i=1;i<=n;i++){
            if(a[i].best!=-1){
                a[i].best=-1;
                if(a[i].)
            }
        }

        **/


        /*/tiaoshi
        cout.tie(0);
        cout<<'\n'<<"text"<<'\n';
        for(int i=1;i<=n;i++){
            cout<<a[i].one<<" "<<a[i].two<<" "<<a[i].tre<<'\n';
        }
        cout<<'\n';
        for(int i=1;i<=n;i++){
            cout<<pone[i].one<<" "<<ptwo[i].two<<" "<<ptre[i].tre<<'\n';
        }
        */
        cout<<ans<<'\n';

    }


    return 0;
}
