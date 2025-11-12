#include<iostream>
#include<algorithm>

using namespace std;

#define Debug 2
#define steam "seat"
int h[110];
int main(){
	if (Debug == 1){
        string c;
        cin>>c;
		freopen((string(steam)+c+".in").c_str(),"r",stdin);
	} else if (Debug == 2) {
		freopen(steam".in","r",stdin);
		freopen(steam".out","w",stdout);
	}

    int n,m,x;
    cin>>n>>m;
    for(int i =1;i<=n*m;i++) {
        cin>>h[i];
    }
    x=h[1];
    sort(h+1,h+m*n+1,[](int a,int b){return a>b;});
    int id=0;
    for(int i=1;i<=n*m;i++) {
        if (h[i] == x)id = i-1;
    }
    cout<<(id/n)+1<<" ";
    cout<<((id%(2*n))<n?(id%(2*n)+1):2*n-id%(2*n));
	return 0;
}// 100 pts
// O(n^2)
