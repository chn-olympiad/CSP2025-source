#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int a[105];
int s[15][15];
ll n,m,num,R_num;
bool zf=true;
void dfs(ll hang,ll line){
	if(hang>n){
		hang=n;
		line++;
		s[hang][line]=a[num];
		num--;
		zf=0;
	}else{
		if(hang<1){
		    hang=1;
		    line++;
		    s[hang][line]=a[num];
		    num--;
		    zf=1;
	    }else{
	    	s[hang][line]=a[num];
	        num--;
		}	
	}
	if(s[hang][line]==R_num){
		cout<<line<<' '<<hang;
		return ;
	}
	if(zf==true)dfs(hang+1,line);
	else dfs(hang-1,line);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
		R_num=a[1];
	}
	sort(a+1,a+n*m+1);
	num=n*m;
	dfs(1,1);
	return 0;
}
