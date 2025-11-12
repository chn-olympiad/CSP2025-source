#include<bits/stdc++.h>
using namespace std;
int t,n,want[100010];
struct node{
    int id,a,b,c;
    bool operator <(const node &W)const{
		return id>W.id;
	}
}m[100010];
struct nod{
	int id,sum;
	bool operator <(const nod &W)const{
		return sum<W.sum;
	}
};
priority_queue<nod> q1,q2,q3;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        for(int i=1;i<=n;i++){
            m[i].a=m[i].b=m[i].c=m[i].id=0;
        }
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>m[i].a>>m[i].b>>m[i].c;
            if(m[i].a>=m[i].b&&m[i].a>=m[i].c){
				m[i].id=m[i].a-max(m[i].b,m[i].c);
            }else if(m[i].b>=m[i].a&&m[i].b>=m[i].c){
                m[i].id=m[i].b-max(m[i].a,m[i].c);
            }else{
                m[i].id=m[i].c-max(m[i].b,m[i].a);
            }
        }
        sort(m+1,m+n+1);
        int u=n/2,ans=0,c1=0,c2=0,c3=0,T=0,x=0;
        for(int i=1;i<=n;i++){
			if(m[i].a>=m[i].b&&m[i].a>=m[i].c){
				if(c1<u){
					ans+=m[i].a;
					c1++;
				}else{
					x=1;
					T=i;
					break;
				}
            }else if(m[i].b>=m[i].a&&m[i].b>=m[i].c){
                if(c2<u){
					ans+=m[i].b;
					c2++;
				}else{
					x=2;
					T=i;
					break;
				}
            }else{
                if(c3<u){
					ans+=m[i].c;
					c3++;
				}else{
					x=3;
					T=i;
					break;
				}
            }
		}
		if(!T){
			cout<<ans<<"\n";
			continue;
		}
        for(int i=T;i<=n;i++){
			if(x==1){
				ans+=max(m[i].b,m[i].c);
			}else if(x==2){
				ans+=max(m[i].a,m[i].c);
			}else{
				ans+=max(m[i].a,m[i].b);
			}
		}
        cout<<ans<<"\n";
    }
    return 0;
}
