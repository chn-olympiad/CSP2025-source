#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i == 1){
			b = a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	/*for(int i=1;i<=n*m;i++){
		cout<<a[i]<<" ";
	}*/
	int c=0,r=0;
	for(int i=1;i<=n*m;i++){
		if(i%n == 1){
			c++;
			if(c%2 == 1){
				r = 1;
			}
			else{
				r = n;
			}
	    }
	    else{
			if(c%2 == 1){
				r++;
			}
			else{
				r--;
			}
		}
		if(a[i] == b){
			cout<<c<<" "<<r;
			return 0;
		}
		//cout<<c<<" "<<r<<endl;
	}
    return 0;
}
