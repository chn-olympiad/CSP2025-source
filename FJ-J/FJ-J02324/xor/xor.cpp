#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int b[500005];
priority_queue<pair<int,int> > q;
void asdf(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if ((b[j]^b[i-1])==k){
//				cout<<"      "<<i<<' '<<j<<' '<<b[i-1]<<' '<<b[j]<<' '<<(b[j]^b[i-1])<<' '<<k<<endl; 
				q.push(make_pair(-i,-j));
			}
		}
	}
	int ans=0,l=-1,qtx,qty;
	while(!q.empty()){
		qtx=-q.top().first;
		qty=-q.top().second;
		q.pop();
//		cout<<qtx<<' '<<qty<<' '<<l<<' '<<ans<<endl;
		if(qtx<=l){
			l=min(l,qty);
		}else{
			ans++;
			l=qty;
		}
//		cout<<qtx<<' '<<qty<<' '<<l<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
	return;
}
void ghjk(){
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
//	cout<<"              ";
//	for(int i=1;i<=n;i++){
//		cout<<b[i]<<' ';
//	}cout<<endl;
	if (n<=1000){
		asdf();
	}else{
		ghjk();
	}
	return 0;
} 
/*
4 0
2 1 0 3

*/
