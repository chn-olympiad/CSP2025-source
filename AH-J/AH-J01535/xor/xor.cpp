#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
bool vis[N];
int cnt;
queue<int> q;
void search(){
	while(!q.empty()){
		int x,y;
		x=q.front();
		q.pop();
		y=q.front();
		q.pop();
		int l=x+1,r=l,num;
		while(l<=r&&r<y){
			num=a[l]^a[r];
			if(num<k){
				r+=1;
			}else if(num>k){
				l+=1;
			}else{
				q.push(x);
				q.push(l);
				q.push(r);
				q.push(y);
				cnt++;
				break;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
			vis[i]=true;
			q.push(i);
			if(i!=1&&i!=n) q.push(i);
		}else if(i==1){
			q.push(0);
		}
	}
	if(!vis[n]){
		q.push(n+1);
	}
	if(k!=0) search();
	cout<<cnt<<endl;
	return 0;
}
