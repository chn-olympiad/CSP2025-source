#include<bits/stdc++.h>
using namespace std;
int cj[105];
bool cmp(int &a,int &b){
	return a>b; 
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>cj[i];
	}
	int mb=cj[1];
	sort(cj+1,cj+n*m+1,cmp);
	int i;
	for(i=1;cj[i]!=mb;){
		i++;
	}
	cout<<((i-1)/n)+1<<" ";
	int j=(i-1)%(2*n);
	if(j>=n){
		cout<<n-((j+1)%n)+1;
	}else cout<<j+1;
    return 0;
}