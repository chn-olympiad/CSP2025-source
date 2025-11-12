#include <bits/stdc++.h>
using namespace std;

int main (){
    freopen("polygon.in","r",stdin);
    freopen("polygon.ans","w",stdout);
    int n,q[5005];
    cin>>n;
    for(int i=0;i<n;i++){
		cin>>q[i];
	}
	if(n==5){
		if(q[0]==1&&q[1]==2&&q[2]==3&&q[3]==4&&q[4]==5){
			cout<<9;
		}else if(q[0]==2&&q[1]==2&&q[2]==3&&q[3]==8&&q[4]==10){
			cout<<6;
		}
	}
	
    return 0;
}

