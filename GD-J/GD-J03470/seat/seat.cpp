#include<bits/stdc++.h> 
using namespace std;
int n,m,re;
int que[150];
int cnt,a1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	que[cnt++]=a1;
	for(int i=1;i<n*m;i++){
		cin>>que[cnt++];
	}
	sort(que,que+cnt,cmp);
	for(int i=0;i<cnt;i++){
		if(a1==que[i]){
			re=i+1;
			break;
		}
	}
	int r=0,re2=re;
	while(re2>=n){
		re2-=n;
		r++;
	}if(re2!=0)++r;
	cout<<r<<' ';
	if(r%2==1){
		if(re2==0) cout<<n;
		else cout<<re2;
	}else{
		if(re2==0) cout<<1;
		else cout<<n+1-re2;
	}
	return 0;
}
