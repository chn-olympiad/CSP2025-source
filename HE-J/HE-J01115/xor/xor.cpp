#include<iostream>
#include<cstdio>
#include<queue>
#define var long long
#define maxn 500001
using namespace std;
var s[maxn],n,k;
struct node{
	var l,r;
};
queue<node> t; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	var a;
	s[0] = 0;
	for(var i=1;i<=n;i++){
		cin>>a;
		s[i] = s[i-1]^a;
	}
	node a0; a0.l=1;a0.r=n;
	t.push(a0);
	var ans=0;
	
	while(!t.empty()){
		node temp = t.front(); t.pop();
		var len = temp.r-temp.l+1;
		bool isb = 0;
		for(var l=1;l<=len;l++){
			for(var i=temp.l;i<=temp.r;i++){
				var r0=i+l-1;
				if(r0>temp.r) break;
				if((s[r0]^s[i-1])==k){
					ans++; isb=1;
					node aa; aa.l=temp.l; aa.r = i-1;
					node bb; bb.l=r0+1; bb.r = temp.r;
					t.push(aa); t.push(bb);
					//cout<<i<<' '<<r0<<' '<<s[i-1]<<' '<<s[r0]<<' '<<(s[r0]^s[i-1])<<endl; 
					break;
				}
			}
			if(isb) break;
		}
	}
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
