#include <bits/stdc++.h>
using namespace std;
int n,m,a[10010],mp[110][110],mu,flag,xn,xm;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
        cin>>n>>m>>mu;a[1]=mu;
         int s=n*m;
         for(int i=2;i<=s;i++){
            cin>>a[i];}
            sort(a+1,a+s+1);
         for(int i=s;i>=1;i--){
            if(a[i]==mu){
				flag=s-i+1;
				}
            }
			if(flag%n==0){
				xm=flag/n;
				if(xm%2==0) xn=1;
				else xn=n;
				}
			else{
				xm=(flag/n)+1;
				if(xm%2==0) xn=n-(flag%n)+1;
				else xn=flag%n;
				}
				cout<<xm<<" "<<xn;
				fclose(stdin);
				fclose(stdout);
        return 0;
}



