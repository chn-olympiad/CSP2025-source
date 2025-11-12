#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int ma1,ma2;
	int ret,id1,id2;
}Node[N];
bool cmp(node a,node b){
	return a.ret>b.ret;
}
int o[3];
int t[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		t[0]=0,t[1]=0,t[2]=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>o[0]>>o[1]>>o[2];
			int maxn=-1;
			for(int j=0;j<3;j++){
				if(o[j]>maxn){
					maxn=o[j],Node[i].id1=j;
					Node[i].ma1=o[j];
				}
			}
			maxn=-1;
			for(int j=0;j<3;j++){
				if(o[j]>maxn and j!=Node[i].id1){
					maxn=o[j],Node[i].id2=j;
					Node[i].ma2=o[j];
				}
			}
			Node[i].ret=Node[i].ma1-Node[i].ma2;
		}
		sort(Node+1,Node+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			int id1=Node[i].id1,id2=Node[i].id2;
			if(t[id1]==n/2){
				t[id2]++;
				ans+=Node[i].ma2;
			}
			else{
				t[id1]++;
				ans+=Node[i].ma1;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}



