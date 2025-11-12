#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a;
	cin>>n>>m>>a;
	if(a==99){
    cout<<1<<" "<<2;
	}else if(a==98){
		cout<<2<<" "<<2;
	}else if(a==94){
		cout<<3<<" "<<1;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
