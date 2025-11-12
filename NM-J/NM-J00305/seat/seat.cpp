#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,bool> a,pair<int,bool> b){
	return a.first>b.first;
}
struct pos{int x;int y;};
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
    cin>>n>>m;
    pair<int,bool> a[n*m+10];
    for(int i=1,x;i<=n*m;i++){
    	cin>>x;
    	a[i]={x,(i==1?1:0)};
	}
	sort(a+1,a+n*m+1,cmp);
	int cur=1;
	for(int i=1;i<=n*m;i+=n){
		if(cur%2==0){
			for(int j=i+n-1;j>=i;j--){			
				if(a[j].second==1)cout<<(int)(i/n+1)<<" "<<j%n+1;
			}
			cur+=1;
		}
		else{
			for(int j=i;j<i+n;j++){
				if(a[j].second==1)cout<<(int)(i/n+1)<<" "<<j-i+1;
			}
			cur+=1;
		}
	}
}


