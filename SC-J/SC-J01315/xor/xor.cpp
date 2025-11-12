#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5+5;
int B[21];
struct node{
	int book[21]={0};
}a;
node qwq[N]={a};
node ItoN(LL num){
	int i=1;
	node ans;
	while(num){
		if(num&1){
			ans.book[i]++;
		}
		num/=2;
		i++;
	}
	return ans;
}
node Nadd(node a,node b){
	node ans;
	for(int i=1;i<=20;i++){
		ans.book[i]=a.book[i]+b.book[i];
	}
	for(int i=1;i<=20;i++){
		if(ans.book[i]&1);
		else ans.book[i]=0;
	}
	return ans;
}
node Naaa(node a,node b){
	node ans;
	for(int i=1;i<=20;i++){
		ans.book[i]=a.book[i]-b.book[i];
	}
	for(int i=1;i<=20;i++){
		if(ans.book[i]&1);
		else ans.book[i]=0;
	}
	return ans;
}
bool NandN(node a,node b){
	for(int i=1;i<=20;i++){
		if(a.book[i]+b.book[i]!=0&&a.book[i]*b.book[i]==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	LL k;
	cin>>n>>k;
	node K=ItoN(k);
	for(int i=1;i<=n;i++){
		LL h;cin>>h;
		node H=ItoN(h);
		qwq[i]=Nadd(qwq[i-1],H);
	}
	int ans=0,s=1;
	for(int r=1;r<=n;r++){
		int l=s;	
		for(;l<=r;l++){
			if(NandN(Naaa(qwq[r],qwq[l-1]),K)){
//				cout<<l<<' '<<r<<'\n';
				s=r+1;
				ans++;
				break;
			}else{
//				cout<<l<<' '<<r<<'\n';
			} 
		}
	}
	cout<<ans;
	return 0;
} 