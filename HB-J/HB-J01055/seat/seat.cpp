#include<bits/stdc++.h>
using namespace std;
int s[100+10]={0};
int main(){
    int n,m,a,b,cnt=0,c,r;
    cin>>n>>m>>a;
    b=a;
    s[b]=1;
    for(int i=1;i<n*m;i++){
        cin>>a;
        s[a]=1;
    }
    for(int i=100;i>=b;i++){
        if(s[i]==1)cnt++;
    }
    int hang=cnt%n,lie=cnt/n;
    if(hang==0){
		if(lie%2==1){
			c=n;
			r=lie;
		}
		else if(lie%2==0){
			c=1;
			r=lie;
		}
	}
	else if(hang!=0){
		if(lie%2==0){
			c=lie+1;
			r=hang;
		}
		else if(lie%2==1){
			c=n+1-hang;
			r=lie+1;
		}
	}
    cout<<c<<' '<<r;
    return 0;
}
