#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;
vector<int>v;
int m,n,a,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	scanf("%d",&n);scanf("%d",&m);
	scanf("%d",&a);v.push_back(a);
	for(int i=0;i<n*m-1;i++){
		scanf("%d",&t);v.push_back(t);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n*m;i++){
            cout<< v[i]<<endl;
		if(v[i]==a){
			t=n*m-i;
            cout<<t<<' ';
			//break;
		}
	}
	int k=t/n,l=t%n;
	if(k%2==1 && l!=0){
		cout<<n-l+1<<' '<<k+1 ;
	}
	else {
            if(l==0)cout<<l+1;
            else cout<<l;
            cout<<' '<<k+1;
	}
    return 0;
}
