#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int cj[n*m];//chengji
    if(n<=1&&m<=1){
		cout<<"1 1";
		return 0;
	}else if(n<=1&&m<=10){
		for(int i = 0;i<m;i++){
			cin>>cj[i];
		}
		for(int i = 0;i<m;i++){
		}
	}
    
    return 0;
}
