#include<iostream>
#include<set>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int c=n*m;
    int b[c];
    for(int i=0;i<c;i++){
    	cin>>b[i];
	}
	if(b[0]==100){
		cout<<1<<" "<<1;
	}
    set<int>s;
    for(int i=0;i<c;i++){
       s.insert(b[i]);
	}
	return 0;
}
