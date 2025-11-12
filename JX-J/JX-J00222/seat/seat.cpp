#include<bits/stdc++.h>
using namespace std;
int s1[114514];
bool pmo(int x,int y){
    return y<x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,a,ans,t=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>s1[i];
	}
	a=s1[1];
	sort(s1+1,s1+n*m+1,pmo);
	for(int i=1;i<=n*m;i++){
        if(s1[i]==a){
            ans=i;
            break;
        }
	}
	int ni=1,nj=0;
	for(int i=1;i<=ans;i++){
            nj+=t;
            if(nj>m||nj<1){
                nj-=t;
                t=t*-1;
                ni+=1;
            }
       }
	cout<<ni<<' '<<nj;
	return 0;
}
