#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct str{
	int num;
	int add;
}s[10005];
bool cmp(str u,str v){
	return u.num>v.num;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==1 && m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&s[i].num);
		if(i==1)  s[i].add=1;
		else  s[i].add=0;
		//cout<<s[i].num<<" ";
	}
	sort(s+1,s+n*m+1,cmp);
	if(n==1){
		int pos;
		for(pos=1;pos<=m;pos++){
			if(s[pos].add==1){
				break;
			}
		}
		cout<<1<<" "<<pos;
		return 0;
	}
	if(m==1){
		int pos;
		for(pos=1;pos<=n;pos++){
			if(s[pos].add==1){
				break;
			}
		}
		cout<<pos<<" "<<1;
		return 0;
	}
	/*
	for(int i=1;i<=n*m;i++){
		cout<<i<<" ";
		cout<<s[i].num<<" "<<s[i].add<<" "<<endl;
	}
	*/
	int x=1,y=1,pos=0;
	while(x!=n || y!=m){
	    pos++;
		//cout<<x<<" "<<y<<" "<<pos<<endl;
		if(s[pos].add==1)  break;
		if(x%2==1){
			if(y==m){
				x++;
			}
			else{
				y++;
			}
		}
		else{
			if(y==1){
				x++;
			}
			else{
				y--;
			}
		}
	}
	cout<<x<<" "<<y;
	//cout<<endl<<pos<<" "<<s[pos].add;
	return 0;
}
