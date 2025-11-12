#include<bits/stdc++.h>
using namespace std;
int n,m,k=1,x,y,q;
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
    cin>>n>>m>>y;
    for(int i=1;i<=n*m-1;i++){
        cin>>x;
        if(x>y) k++;
    }
    q=(k/n)*n;
    if(k%n==0){
        cout<<k/n<<" ";
        if((k/n)%2==1) cout<<n<<endl;
        else cout<<"1"<<endl;
    }
    else{
        cout<<k/n+1<<" ";
        if((k/n+1)%2==1) cout<<k-q<<endl;
        else cout<<n-(k-q)+1<<endl;
    }
	return 0;
}