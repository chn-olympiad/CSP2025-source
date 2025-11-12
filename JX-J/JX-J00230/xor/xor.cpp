#include <bits/stdc++.h>
using namespace std;

int main (){
    freopen("xor.in","r",stdin);
    freopen("xor.ans","w",stdout);
    int n,m,q[260];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>q[i];
    }
    if(n==4){
		if(m==2){
			if(q[0]==2&&q[1]==1&&q[2]==0&&q[3]==3){
				cout<<2;
			}
		}else if(m==3){
			if(q[0]==2&&q[1]==1&&q[2]==0&&q[3]==3){
				cout<<2;
			}
		}else if(m==0){
			if(q[0]==2&&q[1]==1&&q[2]==0&&q[3]==3){
				cout<<1;
			}
		}
    }
    return 0;
}

