#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::freopen;
using std::priority_queue;
const int N=5e5+5;
struct Node{
	Node(int a=0,int b=0):l(a),r(b){ }
	bool operator<(Node n) const{
		return r>n.r;
	}
	int l,r;
};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[N];
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	priority_queue<Node> q;
	int x=0;
	for(int l=0;l<n;l++){
		x=0;
		for(int r=l;r<n;r++){
			x^=a[r];
			if(x==k){
				q.push(Node(l,r));
				break;
			}
		}
	}
	Node temp;
	int u=-1,ans=0;
	while(!q.empty()){
		temp=q.top();
		q.pop();
		if(temp.l>u){
			u=temp.r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}