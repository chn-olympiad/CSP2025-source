#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
};    
int lis[110],n,m,f,c=0,r=0,l,s = 1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    l = n*m;
    for(int i=1;i<=l;i++){
		if(i == 1){
		    cin>>f;
		    lis[i] = f;
		}else{
			cin>>lis[i];
			if(lis[i] > f) s++;
		}
	} 
	if(s==n) c = 1;
	else c = s/n+1;
	s %= 2*n;
	if(s<=n) r=s;
	else r=2*n-s+1;
	cout<<c<<' '<<r;
    return 0;
}     
