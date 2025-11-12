#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,ans,i,j,c;
int b[10009];
bool cmp(int x,int y){
	return x>y;
	}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>b[i];
	}
	c=b[1];
	sort(b+1,b+1+n*m,cmp);
	
	j=1;
	ans=0;
	for(i=0;ans<=n*m;){
		if(j%2==1){
			i++;
		}else{
			i--;
		}
		if(i==m+1){
			j++;
			i--;
		}else if(i==0&&j!=1){
			j++;
			i++;
		}
		ans++;	
		if(b[ans]==c){
			cout<<j<<" "<<i<<endl;
			return 0;
	}
}
	return 0;
}
/*
in:
3 3
94 95 96 97 98 99 100 93 92

out:
3 1
*/
