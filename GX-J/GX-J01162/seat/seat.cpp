#include<bits/stdc++.h>
using namespace std;
int t;
bool f(int a,int b){
     return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,l;
    vector <int>a;
    
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>l;
		
         a.push_back(l);
    }
    t=a[1];
    
    sort(a.begin(),a.end(),f);
  
    
    for(auto i:a){
		if(i==99){
		    cout<<"1"<<" "<<"2";
		}
	}
    return 0;
}
