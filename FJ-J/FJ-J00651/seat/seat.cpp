#include<iostream>
using namespace std;
int n,m,a=-1,b,c=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>b;
			if(a==-1) a=b;
			else if(b>a) c++;
		}
	}
	if(((c-1)/n+1)%2) cout<<((c-1)/n+1)<<' '<<((c-1)%n+1)<<endl;
	else cout<<((c-1)/n+1)<<' '<<(n-((c-1)%n))<<endl;
	return 0;
}
