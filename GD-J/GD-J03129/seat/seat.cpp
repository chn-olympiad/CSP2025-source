#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N*N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	
	int n,m,a1,x=1,y=1,t=0;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> a[i];
	a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>0;i--){
		if(t==0){
			if(y>n) x++,y--,t=1;
			if(a[i]==a1){
				cout << x << " " << y << "\n";
				break;
			}
			if(t==0) y++;
			else y--;
		}
		else if(t==1){
			if(y<1) x++,y++,t=0;
			if(a[i]==a1){
				cout << x << " " << y << "\n";
				break;
			}
			if(t==1) y--;
			else y++;
		}
	}
	
    fclose(stdin);
    fclose(stdout);
    return 0;
}
