#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,ans;
int a[N];
bool check(int x,int y){
	for(int i=1;i<=y;i++){
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		if(check(n,i)) ans++;
	}
	cout<<ans;
	return 0;
} 
