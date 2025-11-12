#include<bits/stdc++.h>
using namespace std;
void fre(){
	 freopen("polygon.in","r",stdin);
	 freopen("polygon.out","w",stdout);
}
bool chk(int a,int b,int c){
	int cnt=0,maxx=0;
	maxx=max(a,b);
	maxx=max(maxx,c);
	cnt=a+b+c;
	if(cnt>2*maxx)return 1;
	return 0;
}
int n,l[5010];
int main(){
	fre();
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	if(n==3){
		int a=l[1],b=l[2],c=l[3];
		if(chk(a,b,c))cout<<1;
		else cout<<0;
	}
	cout<<"Sorry";
	return 0;
}

//12pts

