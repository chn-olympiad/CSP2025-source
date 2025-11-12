#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,maxn=-1;
    cin>>n>>m;
    int s[999999999];
    for(int i=0;i<n*m;i++){
    	cin>>s[i];
	}
	for(int i=0;i<n*m;i++){
		if(s[i]>maxn){
			int x;
			s[i]=x;
			maxn=s[i];
			maxn=x;
		}
    }
    cout << s;
	return 0;
}

