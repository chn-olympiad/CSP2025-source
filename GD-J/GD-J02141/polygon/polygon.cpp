#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct choose{
	int max;
	int num;
	int i;
};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int ans=0,n,l[5005];
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>l[i];
	}
	choose a={l[1],l[1],1};
	queue<choose>q;
	q.push(a);
	while(!q.empty()){
		choose t = q.front();
		q.pop();
		if(t.num>t.max*2){
			ans++;
			ans%=998244353;
		}
		else{
			for(int i=t.i+1;i<=n;++i){
				choose newc = {max(t.max,l[i]),t.num+l[i],i};
				cout<<newc.i<<" "<<newc.max<<" "<<newc.num<<endl;
				q.push(newc);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
