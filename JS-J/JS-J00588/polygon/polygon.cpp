#include<bits/stdc++.h>
using namespace std;
long long int n,cnt=0,d=3,All;
bool jud=true;
int a[100001],ans[1000001];
bool Judge(int a[]){
	All=0;
	for(int i=0;i<d-1;d++){
		All+=a[i];
	} 
	if(All>=2*a[d-1]) return true;
	return false;
}
/*int dfs(int t){
	if()_
}*/

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) jud=false;
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if(a[j-1]>a[j]) swap(a[j-1],a[j]);
		}
	}
	while(d<=n){
        if(a) cnt++; 
        d++;  
	}
	cout<<cnt;
	//dfs(2);
}
